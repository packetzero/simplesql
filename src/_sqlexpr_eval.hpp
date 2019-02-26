#pragma once
#include "../include/simplesql_tree.h"


/*
 * SqlTreeExprEval is a visitor that evaluates expressions.
  */
struct SqlTreeExprEval : public SqlTreeVisitor<DynVal>, public SqlTreeExprVisitor<DynVal>  {

  SqlTreeExprEval(RuntimeState &state_) : state(state_) {}

  virtual DynVal visit(SPCtxNode spNode, int level) override {
    switch(spNode->getType()) {
      case NODE_OPCOMPARE:
        return visit(*(static_cast<CtxOpCompare*>(spNode.get())), level);
      case NODE_OPARITH:
        return visit(* static_cast<CtxOpArith*>(spNode.get()), level);
      case NODE_LITERAL:
        return visit(* static_cast<CtxLiteralValue*>(spNode.get()), level);
      case NODE_GETVAL:
        return visit(* static_cast<CtxOpGetValue*>(spNode.get()), level);
      case NODE_INLIST:
        return visit(* static_cast<CtxOpInList*>(spNode.get()), level);
      case NODE_LIKE:
        return visit(* static_cast<CtxOpLike*>(spNode.get()), level);
      case NODE_EXPR_LIST:
        return visit(* static_cast<CtxExprList*>(spNode.get()), level);
      case NODE_FUNCTION_CALL:
        return visit(* static_cast<CtxFunctionCall*>(spNode.get()), level);
      case NODE_UNARY_OP:
        return visit(* static_cast<CtxUnaryOp*>(spNode.get()), level);
      default:
        break;
    }
    DynVal retval;
    return retval;
  }

  DynVal visit(CtxUnaryOp &node, int level) override {
    DynVal val = visit(node._expr, level);

    switch(node._op) {
      case UOP_PLUS:
        return val;
      case UOP_NOT:
        return !val.as_i32();
      case UOP_MINUS:
      {
        if (val.type() == TFLOAT32 || val.type() == TFLOAT64) {
          return 0 - val.as_double();
        }
        return 0 - val.as_i64();
      }
      default:
        ASSERT(false);
        break;
    }
    return val;
  }

  DynVal visit(CtxOpCompare &node, int level) override {
    DynVal left = visit(node._left, level+1);
    if(!left.valid()) {
      ASSERT(false);
      return left;
    }

    // short-circuit eval
    if (node._op == OP_OR && left.as_i32() != 0) {
      if (state.trace()) {
        //printf("%s%s OR %s\n", CtxUtil::indentstr(level).c_str(), _left->to_s().c_str(), _right->to_s().c_str());
        //printf("%s# shortcircuit left=true (%s)\n", CtxUtil::indentstr(level).c_str(), left.as_s().c_str());
      }
      return DynVal(true);
    }
    if (node._op == OP_AND && left.as_i32() == 0) {
      if (state.trace()) {
        //printf("%s%s AND %s\n", CtxUtil::indentstr(level).c_str(), _left->to_s().c_str(), _right->to_s().c_str());
        //printf("%s# shortcircuit left=false (%s)\n", CtxUtil::indentstr(level).c_str(), left.as_s().c_str());
      }
      return DynVal(false);
    }

    DynVal right = visit(node._right, level+1);
    switch(node._op) {
      case OP_OR:
        return right;
      case OP_AND:
        return right;
      case OP_EQ:
        if (left.type() == right.type() && left.type() != TSTRING) {
          if (left.type() == TFLOAT64) {
            return left.as_double() == right.as_double();
          } else {
            return left.as_i64() == right.as_i64();
          }
        } else {
          return left.as_s() == right.as_s();
        }
      default:
        break;
    }

    ASSERT(false);
    return DynVal();
  }

  DynVal visit(CtxOpArith &node, int level) override {
    DynVal left = visit(node._left, level+1);
    if(!left.valid()) {
      ASSERT(false);
      return left;
    }

    DynVal right = visit(node._right, level+1);
    if (!right.valid()) {
      ASSERT(false);
      return right;
    }
    switch(node._op) {
      case OP_ADD:
        if (left.type() == TFLOAT64 || left.type() == TFLOAT32) {
          return left.as_double() + right.as_double();
        }
        return left.as_i64() + right.as_i64();
      case OP_SUB:
        if (left.type() == TFLOAT64 || left.type() == TFLOAT32) {
          return left.as_double() - right.as_double();
        }
        return left.as_i64() - right.as_i64();
      case OP_MUL:
        if (left.type() == TFLOAT64 || left.type() == TFLOAT32) {
          return left.as_double() * right.as_double();
        }
        return left.as_i64() * right.as_i64();
      case OP_DIV:
        // TODO: check for div by zero
        if (left.type() == TFLOAT64 || left.type() == TFLOAT32 || right.type() == TFLOAT64) {
          return left.as_double() / right.as_double();
        }
        return left.as_i64() / right.as_i64();
      default:
        break;
    }

    ASSERT(false);
    return DynVal();
  }

  DynVal visit(CtxOpGetValue &node, int level) override {
    DynVal v = state._valueStore.lookupValue(node._name);
    if (!v.valid()) {
      state.addError("ERROR: unable to resolve value for variable: " + node._name);
      return v;
    }
    return v;
  }

  DynVal visit(CtxLiteralValue &node, int level) override {
    return node._value;
  }

  DynVal visit(CtxOpInList &node, int level) override {
    DynVal val = visit(node.value, level+1);
    if (!val.valid()) {
      state.addError("ERROR: left-hand side of comparison failed to resolve");
      return val;
    }
    bool retval = false;

    if (node.list->items.empty()) {
      state.addError("Empty list for IN");
      return val;
    }

    // render list items into values
    std::vector<DynVal> values;
    CtxExprList *exprList = static_cast<CtxExprList*>(node.list.get());
    for (int i=0; i < exprList->items.size(); i++) {
      DynVal value = visit(exprList->items[i], 0);
      if (!value.valid()) {
        state.addError("ERROR: nth list item did not evaluate: " + std::to_string(i));
        return retval;
      }
      values.push_back(value);
    }

    bool isNumeric = values[0].type() != TSTRING;

    if (isNumeric) {
      for (auto listItem : values) {
        // TODO: a more natural compare across types
        if (val.as_double() == listItem.as_double()) { retval = true; break; }
      }
    } else {
      // string compares
      for (auto listItem : values) {
        if (val.as_s() == listItem.as_s()) { retval = true; break; }
      }
    }
    if (node.isNot) { retval = !retval; }
    return retval;
  }

  static bool is_like(const std::string &subject, std::vector<std::string> parts) {
    size_t pos = 0;
    for (int i=0;i < parts.size() ; i++) {
      if (parts[i].empty()) {
        continue; // indicates '%'
      }
      size_t pos2 = subject.find(parts[i], pos);
      if (pos2 == std::string::npos) { return false; }

      bool preceededByWildcard = (i > 0 && parts[i-1].empty());
      if (!preceededByWildcard && pos2 > pos) {
        return false; // found, but does not start subject
      }
      pos = pos2 + parts[i].size();

      if (pos >= subject.size()) { break; }

      if (i == parts.size()-1) {
        // there is extra suffix
        return false;
      }
    }
    return true;
  }

  DynVal visit(CtxOpLike &node, int level) override {
    DynVal left = visit(node._left, level+1);
    if(!left.valid()) {
      ASSERT(false);
      return left;
    }

    bool retval = is_like(left.as_s(), node._parts);
    if (node._isNot) { retval = !retval; }
    return retval;
  }

  DynVal visit(CtxExprList &node, int level) override {
    return 0;  // parent should not visit this node anyways
  }

  DynVal visit(CtxFunctionCall &node, int level) override {
    std::vector<DynVal> values;
    for (auto expr : node._params) {
      values.push_back(visit(expr, level));
    }
    DynVal result = state.call(node._function_name, values);
    if (!result.valid()) {
      state.addError("Error calling function:" + node._function_name);
      return 0;
    }
    return result;
  }

protected:

  RuntimeState &state;
};
