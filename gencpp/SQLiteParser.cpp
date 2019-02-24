
// Generated from ./SQLite.g4 by ANTLR 4.7.2


#include "SQLiteVisitor.h"

#include "SQLiteParser.h"


using namespace antlrcpp;
using namespace antlr4;

SQLiteParser::SQLiteParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SQLiteParser::~SQLiteParser() {
  delete _interpreter;
}

std::string SQLiteParser::getGrammarFileName() const {
  return "SQLite.g4";
}

const std::vector<std::string>& SQLiteParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SQLiteParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ParseContext ------------------------------------------------------------------

SQLiteParser::ParseContext::ParseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::ParseContext::EOF() {
  return getToken(SQLiteParser::EOF, 0);
}

std::vector<SQLiteParser::Sql_stmt_or_exprContext *> SQLiteParser::ParseContext::sql_stmt_or_expr() {
  return getRuleContexts<SQLiteParser::Sql_stmt_or_exprContext>();
}

SQLiteParser::Sql_stmt_or_exprContext* SQLiteParser::ParseContext::sql_stmt_or_expr(size_t i) {
  return getRuleContext<SQLiteParser::Sql_stmt_or_exprContext>(i);
}

std::vector<SQLiteParser::ErrorContext *> SQLiteParser::ParseContext::error() {
  return getRuleContexts<SQLiteParser::ErrorContext>();
}

SQLiteParser::ErrorContext* SQLiteParser::ParseContext::error(size_t i) {
  return getRuleContext<SQLiteParser::ErrorContext>(i);
}


size_t SQLiteParser::ParseContext::getRuleIndex() const {
  return SQLiteParser::RuleParse;
}


antlrcpp::Any SQLiteParser::ParseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitParse(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::ParseContext* SQLiteParser::parse() {
  ParseContext *_localctx = _tracker.createInstance<ParseContext>(_ctx, getState());
  enterRule(_localctx, 0, SQLiteParser::RuleParse);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQLiteParser::UNSUPPORTED_KEYWORDS)
      | (1ULL << SQLiteParser::OPEN_PAR)
      | (1ULL << SQLiteParser::PLUS)
      | (1ULL << SQLiteParser::MINUS)
      | (1ULL << SQLiteParser::K_CAST)
      | (1ULL << SQLiteParser::K_CURRENT_DATE)
      | (1ULL << SQLiteParser::K_CURRENT_TIME)
      | (1ULL << SQLiteParser::K_CURRENT_TIMESTAMP))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (SQLiteParser::K_EXISTS - 70))
      | (1ULL << (SQLiteParser::K_NOT - 70))
      | (1ULL << (SQLiteParser::K_NULL - 70))
      | (1ULL << (SQLiteParser::K_SELECT - 70)))) != 0) || ((((_la - 140) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 140)) & ((1ULL << (SQLiteParser::K_VALUES - 140))
      | (1ULL << (SQLiteParser::IDENTIFIER - 140))
      | (1ULL << (SQLiteParser::NUMERIC_LITERAL - 140))
      | (1ULL << (SQLiteParser::STRING_LITERAL - 140))
      | (1ULL << (SQLiteParser::BLOB_LITERAL - 140))
      | (1ULL << (SQLiteParser::UNEXPECTED_CHAR - 140)))) != 0)) {
      setState(60);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SQLiteParser::OPEN_PAR:
        case SQLiteParser::PLUS:
        case SQLiteParser::MINUS:
        case SQLiteParser::K_CAST:
        case SQLiteParser::K_CURRENT_DATE:
        case SQLiteParser::K_CURRENT_TIME:
        case SQLiteParser::K_CURRENT_TIMESTAMP:
        case SQLiteParser::K_EXISTS:
        case SQLiteParser::K_NOT:
        case SQLiteParser::K_NULL:
        case SQLiteParser::K_SELECT:
        case SQLiteParser::K_VALUES:
        case SQLiteParser::IDENTIFIER:
        case SQLiteParser::NUMERIC_LITERAL:
        case SQLiteParser::STRING_LITERAL:
        case SQLiteParser::BLOB_LITERAL: {
          setState(58);
          sql_stmt_or_expr();
          break;
        }

        case SQLiteParser::UNSUPPORTED_KEYWORDS:
        case SQLiteParser::UNEXPECTED_CHAR: {
          setState(59);
          error();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(65);
    match(SQLiteParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ErrorContext ------------------------------------------------------------------

SQLiteParser::ErrorContext::ErrorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::ErrorContext::UNEXPECTED_CHAR() {
  return getToken(SQLiteParser::UNEXPECTED_CHAR, 0);
}

tree::TerminalNode* SQLiteParser::ErrorContext::UNSUPPORTED_KEYWORDS() {
  return getToken(SQLiteParser::UNSUPPORTED_KEYWORDS, 0);
}


size_t SQLiteParser::ErrorContext::getRuleIndex() const {
  return SQLiteParser::RuleError;
}


antlrcpp::Any SQLiteParser::ErrorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitError(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::ErrorContext* SQLiteParser::error() {
  ErrorContext *_localctx = _tracker.createInstance<ErrorContext>(_ctx, getState());
  enterRule(_localctx, 2, SQLiteParser::RuleError);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLiteParser::UNEXPECTED_CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(67);
        dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken = match(SQLiteParser::UNEXPECTED_CHAR);

          std::string errmsg = "UNEXPECTED_CHAR: " + (dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken != nullptr ? dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken->getText() : "");
          auto e = new RecognitionException(errmsg, this, getInputStream(), _localctx, _localctx->unexpected_charToken);
          _errHandler->reportError(this, *e);
          _localctx->exception = std::current_exception();
          _errHandler->recover(this, _localctx->exception);


        break;
      }

      case SQLiteParser::UNSUPPORTED_KEYWORDS: {
        enterOuterAlt(_localctx, 2);
        setState(69);
        dynamic_cast<ErrorContext *>(_localctx)->unsupported_keywordsToken = match(SQLiteParser::UNSUPPORTED_KEYWORDS);

          std::string errmsg = "UNSUPPORTED_KEYWORD: " + (dynamic_cast<ErrorContext *>(_localctx)->unsupported_keywordsToken != nullptr ? dynamic_cast<ErrorContext *>(_localctx)->unsupported_keywordsToken->getText() : "");
          auto e = new RecognitionException(errmsg, this, getInputStream(), _localctx, dynamic_cast<ErrorContext *>(_localctx)->unsupported_keywordsToken);
          _errHandler->reportError(this, *e);
          _localctx->exception = std::current_exception();
          _errHandler->recover(this, _localctx->exception);


        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmt_or_exprContext ------------------------------------------------------------------

SQLiteParser::Sql_stmt_or_exprContext::Sql_stmt_or_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::Sql_stmtContext* SQLiteParser::Sql_stmt_or_exprContext::sql_stmt() {
  return getRuleContext<SQLiteParser::Sql_stmtContext>(0);
}

SQLiteParser::ExprContext* SQLiteParser::Sql_stmt_or_exprContext::expr() {
  return getRuleContext<SQLiteParser::ExprContext>(0);
}


size_t SQLiteParser::Sql_stmt_or_exprContext::getRuleIndex() const {
  return SQLiteParser::RuleSql_stmt_or_expr;
}


antlrcpp::Any SQLiteParser::Sql_stmt_or_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitSql_stmt_or_expr(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Sql_stmt_or_exprContext* SQLiteParser::sql_stmt_or_expr() {
  Sql_stmt_or_exprContext *_localctx = _tracker.createInstance<Sql_stmt_or_exprContext>(_ctx, getState());
  enterRule(_localctx, 4, SQLiteParser::RuleSql_stmt_or_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLiteParser::K_SELECT:
      case SQLiteParser::K_VALUES: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        sql_stmt();
        break;
      }

      case SQLiteParser::OPEN_PAR:
      case SQLiteParser::PLUS:
      case SQLiteParser::MINUS:
      case SQLiteParser::K_CAST:
      case SQLiteParser::K_CURRENT_DATE:
      case SQLiteParser::K_CURRENT_TIME:
      case SQLiteParser::K_CURRENT_TIMESTAMP:
      case SQLiteParser::K_EXISTS:
      case SQLiteParser::K_NOT:
      case SQLiteParser::K_NULL:
      case SQLiteParser::IDENTIFIER:
      case SQLiteParser::NUMERIC_LITERAL:
      case SQLiteParser::STRING_LITERAL:
      case SQLiteParser::BLOB_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(74);
        expr(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmtContext ------------------------------------------------------------------

SQLiteParser::Sql_stmtContext::Sql_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::Simple_select_stmtContext* SQLiteParser::Sql_stmtContext::simple_select_stmt() {
  return getRuleContext<SQLiteParser::Simple_select_stmtContext>(0);
}

std::vector<tree::TerminalNode *> SQLiteParser::Sql_stmtContext::SCOL() {
  return getTokens(SQLiteParser::SCOL);
}

tree::TerminalNode* SQLiteParser::Sql_stmtContext::SCOL(size_t i) {
  return getToken(SQLiteParser::SCOL, i);
}

SQLiteParser::Select_stmtContext* SQLiteParser::Sql_stmtContext::select_stmt() {
  return getRuleContext<SQLiteParser::Select_stmtContext>(0);
}


size_t SQLiteParser::Sql_stmtContext::getRuleIndex() const {
  return SQLiteParser::RuleSql_stmt;
}


antlrcpp::Any SQLiteParser::Sql_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitSql_stmt(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Sql_stmtContext* SQLiteParser::sql_stmt() {
  Sql_stmtContext *_localctx = _tracker.createInstance<Sql_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, SQLiteParser::RuleSql_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      simple_select_stmt();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQLiteParser::SCOL) {
        setState(78);
        match(SQLiteParser::SCOL);
        setState(83);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(84);
      select_stmt();
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQLiteParser::SCOL) {
        setState(85);
        match(SQLiteParser::SCOL);
        setState(90);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_select_stmtContext ------------------------------------------------------------------

SQLiteParser::Simple_select_stmtContext::Simple_select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::Select_coreContext* SQLiteParser::Simple_select_stmtContext::select_core() {
  return getRuleContext<SQLiteParser::Select_coreContext>(0);
}

tree::TerminalNode* SQLiteParser::Simple_select_stmtContext::K_ORDER() {
  return getToken(SQLiteParser::K_ORDER, 0);
}

tree::TerminalNode* SQLiteParser::Simple_select_stmtContext::K_BY() {
  return getToken(SQLiteParser::K_BY, 0);
}

std::vector<SQLiteParser::Ordering_termContext *> SQLiteParser::Simple_select_stmtContext::ordering_term() {
  return getRuleContexts<SQLiteParser::Ordering_termContext>();
}

SQLiteParser::Ordering_termContext* SQLiteParser::Simple_select_stmtContext::ordering_term(size_t i) {
  return getRuleContext<SQLiteParser::Ordering_termContext>(i);
}

tree::TerminalNode* SQLiteParser::Simple_select_stmtContext::K_LIMIT() {
  return getToken(SQLiteParser::K_LIMIT, 0);
}

std::vector<SQLiteParser::ExprContext *> SQLiteParser::Simple_select_stmtContext::expr() {
  return getRuleContexts<SQLiteParser::ExprContext>();
}

SQLiteParser::ExprContext* SQLiteParser::Simple_select_stmtContext::expr(size_t i) {
  return getRuleContext<SQLiteParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SQLiteParser::Simple_select_stmtContext::COMMA() {
  return getTokens(SQLiteParser::COMMA);
}

tree::TerminalNode* SQLiteParser::Simple_select_stmtContext::COMMA(size_t i) {
  return getToken(SQLiteParser::COMMA, i);
}

tree::TerminalNode* SQLiteParser::Simple_select_stmtContext::K_OFFSET() {
  return getToken(SQLiteParser::K_OFFSET, 0);
}


size_t SQLiteParser::Simple_select_stmtContext::getRuleIndex() const {
  return SQLiteParser::RuleSimple_select_stmt;
}


antlrcpp::Any SQLiteParser::Simple_select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitSimple_select_stmt(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Simple_select_stmtContext* SQLiteParser::simple_select_stmt() {
  Simple_select_stmtContext *_localctx = _tracker.createInstance<Simple_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, SQLiteParser::RuleSimple_select_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    select_core();
    setState(104);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_ORDER) {
      setState(94);
      match(SQLiteParser::K_ORDER);
      setState(95);
      match(SQLiteParser::K_BY);
      setState(96);
      ordering_term();
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQLiteParser::COMMA) {
        setState(97);
        match(SQLiteParser::COMMA);
        setState(98);
        ordering_term();
        setState(103);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_LIMIT) {
      setState(106);
      match(SQLiteParser::K_LIMIT);
      setState(107);
      expr(0);
      setState(110);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLiteParser::COMMA || _la == SQLiteParser::K_OFFSET) {
        setState(108);
        _la = _input->LA(1);
        if (!(_la == SQLiteParser::COMMA || _la == SQLiteParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(109);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_stmtContext ------------------------------------------------------------------

SQLiteParser::Select_stmtContext::Select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLiteParser::Select_or_valuesContext *> SQLiteParser::Select_stmtContext::select_or_values() {
  return getRuleContexts<SQLiteParser::Select_or_valuesContext>();
}

SQLiteParser::Select_or_valuesContext* SQLiteParser::Select_stmtContext::select_or_values(size_t i) {
  return getRuleContext<SQLiteParser::Select_or_valuesContext>(i);
}

std::vector<SQLiteParser::Compound_operatorContext *> SQLiteParser::Select_stmtContext::compound_operator() {
  return getRuleContexts<SQLiteParser::Compound_operatorContext>();
}

SQLiteParser::Compound_operatorContext* SQLiteParser::Select_stmtContext::compound_operator(size_t i) {
  return getRuleContext<SQLiteParser::Compound_operatorContext>(i);
}

tree::TerminalNode* SQLiteParser::Select_stmtContext::K_ORDER() {
  return getToken(SQLiteParser::K_ORDER, 0);
}

tree::TerminalNode* SQLiteParser::Select_stmtContext::K_BY() {
  return getToken(SQLiteParser::K_BY, 0);
}

std::vector<SQLiteParser::Ordering_termContext *> SQLiteParser::Select_stmtContext::ordering_term() {
  return getRuleContexts<SQLiteParser::Ordering_termContext>();
}

SQLiteParser::Ordering_termContext* SQLiteParser::Select_stmtContext::ordering_term(size_t i) {
  return getRuleContext<SQLiteParser::Ordering_termContext>(i);
}

tree::TerminalNode* SQLiteParser::Select_stmtContext::K_LIMIT() {
  return getToken(SQLiteParser::K_LIMIT, 0);
}

std::vector<SQLiteParser::ExprContext *> SQLiteParser::Select_stmtContext::expr() {
  return getRuleContexts<SQLiteParser::ExprContext>();
}

SQLiteParser::ExprContext* SQLiteParser::Select_stmtContext::expr(size_t i) {
  return getRuleContext<SQLiteParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SQLiteParser::Select_stmtContext::COMMA() {
  return getTokens(SQLiteParser::COMMA);
}

tree::TerminalNode* SQLiteParser::Select_stmtContext::COMMA(size_t i) {
  return getToken(SQLiteParser::COMMA, i);
}

tree::TerminalNode* SQLiteParser::Select_stmtContext::K_OFFSET() {
  return getToken(SQLiteParser::K_OFFSET, 0);
}


size_t SQLiteParser::Select_stmtContext::getRuleIndex() const {
  return SQLiteParser::RuleSelect_stmt;
}


antlrcpp::Any SQLiteParser::Select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitSelect_stmt(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Select_stmtContext* SQLiteParser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, SQLiteParser::RuleSelect_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    select_or_values();
    setState(120);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLiteParser::K_UNION) {
      setState(115);
      compound_operator();
      setState(116);
      select_or_values();
      setState(122);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_ORDER) {
      setState(123);
      match(SQLiteParser::K_ORDER);
      setState(124);
      match(SQLiteParser::K_BY);
      setState(125);
      ordering_term();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQLiteParser::COMMA) {
        setState(126);
        match(SQLiteParser::COMMA);
        setState(127);
        ordering_term();
        setState(132);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_LIMIT) {
      setState(135);
      match(SQLiteParser::K_LIMIT);
      setState(136);
      expr(0);
      setState(139);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLiteParser::COMMA || _la == SQLiteParser::K_OFFSET) {
        setState(137);
        _la = _input->LA(1);
        if (!(_la == SQLiteParser::COMMA || _la == SQLiteParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(138);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_or_valuesContext ------------------------------------------------------------------

SQLiteParser::Select_or_valuesContext::Select_or_valuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::Select_coreContext* SQLiteParser::Select_or_valuesContext::select_core() {
  return getRuleContext<SQLiteParser::Select_coreContext>(0);
}

tree::TerminalNode* SQLiteParser::Select_or_valuesContext::K_VALUES() {
  return getToken(SQLiteParser::K_VALUES, 0);
}

std::vector<tree::TerminalNode *> SQLiteParser::Select_or_valuesContext::OPEN_PAR() {
  return getTokens(SQLiteParser::OPEN_PAR);
}

tree::TerminalNode* SQLiteParser::Select_or_valuesContext::OPEN_PAR(size_t i) {
  return getToken(SQLiteParser::OPEN_PAR, i);
}

std::vector<SQLiteParser::ExprContext *> SQLiteParser::Select_or_valuesContext::expr() {
  return getRuleContexts<SQLiteParser::ExprContext>();
}

SQLiteParser::ExprContext* SQLiteParser::Select_or_valuesContext::expr(size_t i) {
  return getRuleContext<SQLiteParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SQLiteParser::Select_or_valuesContext::CLOSE_PAR() {
  return getTokens(SQLiteParser::CLOSE_PAR);
}

tree::TerminalNode* SQLiteParser::Select_or_valuesContext::CLOSE_PAR(size_t i) {
  return getToken(SQLiteParser::CLOSE_PAR, i);
}

std::vector<tree::TerminalNode *> SQLiteParser::Select_or_valuesContext::COMMA() {
  return getTokens(SQLiteParser::COMMA);
}

tree::TerminalNode* SQLiteParser::Select_or_valuesContext::COMMA(size_t i) {
  return getToken(SQLiteParser::COMMA, i);
}


size_t SQLiteParser::Select_or_valuesContext::getRuleIndex() const {
  return SQLiteParser::RuleSelect_or_values;
}


antlrcpp::Any SQLiteParser::Select_or_valuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitSelect_or_values(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Select_or_valuesContext* SQLiteParser::select_or_values() {
  Select_or_valuesContext *_localctx = _tracker.createInstance<Select_or_valuesContext>(_ctx, getState());
  enterRule(_localctx, 12, SQLiteParser::RuleSelect_or_values);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLiteParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        select_core();
        break;
      }

      case SQLiteParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        match(SQLiteParser::K_VALUES);
        setState(145);
        match(SQLiteParser::OPEN_PAR);
        setState(146);
        expr(0);
        setState(151);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLiteParser::COMMA) {
          setState(147);
          match(SQLiteParser::COMMA);
          setState(148);
          expr(0);
          setState(153);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(154);
        match(SQLiteParser::CLOSE_PAR);
        setState(169);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLiteParser::COMMA) {
          setState(155);
          match(SQLiteParser::COMMA);
          setState(156);
          match(SQLiteParser::OPEN_PAR);
          setState(157);
          expr(0);
          setState(162);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SQLiteParser::COMMA) {
            setState(158);
            match(SQLiteParser::COMMA);
            setState(159);
            expr(0);
            setState(164);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(165);
          match(SQLiteParser::CLOSE_PAR);
          setState(171);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_nameContext ------------------------------------------------------------------

SQLiteParser::Type_nameContext::Type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLiteParser::NameContext *> SQLiteParser::Type_nameContext::name() {
  return getRuleContexts<SQLiteParser::NameContext>();
}

SQLiteParser::NameContext* SQLiteParser::Type_nameContext::name(size_t i) {
  return getRuleContext<SQLiteParser::NameContext>(i);
}

tree::TerminalNode* SQLiteParser::Type_nameContext::OPEN_PAR() {
  return getToken(SQLiteParser::OPEN_PAR, 0);
}

std::vector<SQLiteParser::Signed_numberContext *> SQLiteParser::Type_nameContext::signed_number() {
  return getRuleContexts<SQLiteParser::Signed_numberContext>();
}

SQLiteParser::Signed_numberContext* SQLiteParser::Type_nameContext::signed_number(size_t i) {
  return getRuleContext<SQLiteParser::Signed_numberContext>(i);
}

tree::TerminalNode* SQLiteParser::Type_nameContext::CLOSE_PAR() {
  return getToken(SQLiteParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SQLiteParser::Type_nameContext::COMMA() {
  return getToken(SQLiteParser::COMMA, 0);
}


size_t SQLiteParser::Type_nameContext::getRuleIndex() const {
  return SQLiteParser::RuleType_name;
}


antlrcpp::Any SQLiteParser::Type_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitType_name(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Type_nameContext* SQLiteParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 14, SQLiteParser::RuleType_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(175); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(174);
              name();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(177); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(189);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(179);
      match(SQLiteParser::OPEN_PAR);
      setState(180);
      signed_number();
      setState(181);
      match(SQLiteParser::CLOSE_PAR);
      break;
    }

    case 2: {
      setState(183);
      match(SQLiteParser::OPEN_PAR);
      setState(184);
      signed_number();
      setState(185);
      match(SQLiteParser::COMMA);
      setState(186);
      signed_number();
      setState(187);
      match(SQLiteParser::CLOSE_PAR);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

SQLiteParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::Literal_valueContext* SQLiteParser::ExprContext::literal_value() {
  return getRuleContext<SQLiteParser::Literal_valueContext>(0);
}

SQLiteParser::Function_nameContext* SQLiteParser::ExprContext::function_name() {
  return getRuleContext<SQLiteParser::Function_nameContext>(0);
}

tree::TerminalNode* SQLiteParser::ExprContext::OPEN_PAR() {
  return getToken(SQLiteParser::OPEN_PAR, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::CLOSE_PAR() {
  return getToken(SQLiteParser::CLOSE_PAR, 0);
}

std::vector<SQLiteParser::ExprContext *> SQLiteParser::ExprContext::expr() {
  return getRuleContexts<SQLiteParser::ExprContext>();
}

SQLiteParser::ExprContext* SQLiteParser::ExprContext::expr(size_t i) {
  return getRuleContext<SQLiteParser::ExprContext>(i);
}

tree::TerminalNode* SQLiteParser::ExprContext::STAR() {
  return getToken(SQLiteParser::STAR, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_DISTINCT() {
  return getToken(SQLiteParser::K_DISTINCT, 0);
}

std::vector<tree::TerminalNode *> SQLiteParser::ExprContext::COMMA() {
  return getTokens(SQLiteParser::COMMA);
}

tree::TerminalNode* SQLiteParser::ExprContext::COMMA(size_t i) {
  return getToken(SQLiteParser::COMMA, i);
}

SQLiteParser::Column_nameContext* SQLiteParser::ExprContext::column_name() {
  return getRuleContext<SQLiteParser::Column_nameContext>(0);
}

SQLiteParser::Table_nameContext* SQLiteParser::ExprContext::table_name() {
  return getRuleContext<SQLiteParser::Table_nameContext>(0);
}

std::vector<tree::TerminalNode *> SQLiteParser::ExprContext::DOT() {
  return getTokens(SQLiteParser::DOT);
}

tree::TerminalNode* SQLiteParser::ExprContext::DOT(size_t i) {
  return getToken(SQLiteParser::DOT, i);
}

SQLiteParser::Database_nameContext* SQLiteParser::ExprContext::database_name() {
  return getRuleContext<SQLiteParser::Database_nameContext>(0);
}

SQLiteParser::Unary_operatorContext* SQLiteParser::ExprContext::unary_operator() {
  return getRuleContext<SQLiteParser::Unary_operatorContext>(0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_CAST() {
  return getToken(SQLiteParser::K_CAST, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_AS() {
  return getToken(SQLiteParser::K_AS, 0);
}

SQLiteParser::Type_nameContext* SQLiteParser::ExprContext::type_name() {
  return getRuleContext<SQLiteParser::Type_nameContext>(0);
}

SQLiteParser::Select_stmtContext* SQLiteParser::ExprContext::select_stmt() {
  return getRuleContext<SQLiteParser::Select_stmtContext>(0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_EXISTS() {
  return getToken(SQLiteParser::K_EXISTS, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_NOT() {
  return getToken(SQLiteParser::K_NOT, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::PIPE2() {
  return getToken(SQLiteParser::PIPE2, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::DIV() {
  return getToken(SQLiteParser::DIV, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::MOD() {
  return getToken(SQLiteParser::MOD, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::PLUS() {
  return getToken(SQLiteParser::PLUS, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::MINUS() {
  return getToken(SQLiteParser::MINUS, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::LT2() {
  return getToken(SQLiteParser::LT2, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::GT2() {
  return getToken(SQLiteParser::GT2, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::AMP() {
  return getToken(SQLiteParser::AMP, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::PIPE() {
  return getToken(SQLiteParser::PIPE, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::LT() {
  return getToken(SQLiteParser::LT, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::LT_EQ() {
  return getToken(SQLiteParser::LT_EQ, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::GT() {
  return getToken(SQLiteParser::GT, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::GT_EQ() {
  return getToken(SQLiteParser::GT_EQ, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::ASSIGN() {
  return getToken(SQLiteParser::ASSIGN, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::EQ() {
  return getToken(SQLiteParser::EQ, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::NOT_EQ1() {
  return getToken(SQLiteParser::NOT_EQ1, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::NOT_EQ2() {
  return getToken(SQLiteParser::NOT_EQ2, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_IS() {
  return getToken(SQLiteParser::K_IS, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_GLOB() {
  return getToken(SQLiteParser::K_GLOB, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_MATCH() {
  return getToken(SQLiteParser::K_MATCH, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_REGEXP() {
  return getToken(SQLiteParser::K_REGEXP, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_LIKE() {
  return getToken(SQLiteParser::K_LIKE, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_AND() {
  return getToken(SQLiteParser::K_AND, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_OR() {
  return getToken(SQLiteParser::K_OR, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_BETWEEN() {
  return getToken(SQLiteParser::K_BETWEEN, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_IN() {
  return getToken(SQLiteParser::K_IN, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_ISNULL() {
  return getToken(SQLiteParser::K_ISNULL, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_NOTNULL() {
  return getToken(SQLiteParser::K_NOTNULL, 0);
}

tree::TerminalNode* SQLiteParser::ExprContext::K_NULL() {
  return getToken(SQLiteParser::K_NULL, 0);
}


size_t SQLiteParser::ExprContext::getRuleIndex() const {
  return SQLiteParser::RuleExpr;
}


antlrcpp::Any SQLiteParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


SQLiteParser::ExprContext* SQLiteParser::expr() {
   return expr(0);
}

SQLiteParser::ExprContext* SQLiteParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SQLiteParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  SQLiteParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, SQLiteParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(192);
      literal_value();
      break;
    }

    case 2: {
      setState(193);
      function_name();
      setState(194);
      match(SQLiteParser::OPEN_PAR);
      setState(207);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SQLiteParser::OPEN_PAR:
        case SQLiteParser::PLUS:
        case SQLiteParser::MINUS:
        case SQLiteParser::K_CAST:
        case SQLiteParser::K_CURRENT_DATE:
        case SQLiteParser::K_CURRENT_TIME:
        case SQLiteParser::K_CURRENT_TIMESTAMP:
        case SQLiteParser::K_DISTINCT:
        case SQLiteParser::K_EXISTS:
        case SQLiteParser::K_NOT:
        case SQLiteParser::K_NULL:
        case SQLiteParser::IDENTIFIER:
        case SQLiteParser::NUMERIC_LITERAL:
        case SQLiteParser::STRING_LITERAL:
        case SQLiteParser::BLOB_LITERAL: {
          setState(196);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SQLiteParser::K_DISTINCT) {
            setState(195);
            match(SQLiteParser::K_DISTINCT);
          }
          setState(198);
          expr(0);
          setState(203);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SQLiteParser::COMMA) {
            setState(199);
            match(SQLiteParser::COMMA);
            setState(200);
            expr(0);
            setState(205);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SQLiteParser::STAR: {
          setState(206);
          match(SQLiteParser::STAR);
          break;
        }

        case SQLiteParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(209);
      match(SQLiteParser::CLOSE_PAR);
      break;
    }

    case 3: {
      setState(219);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
      case 1: {
        setState(214);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          setState(211);
          database_name();
          setState(212);
          match(SQLiteParser::DOT);
          break;
        }

        }
        setState(216);
        table_name();
        setState(217);
        match(SQLiteParser::DOT);
        break;
      }

      }
      setState(221);
      column_name();
      break;
    }

    case 4: {
      setState(222);
      unary_operator();
      setState(223);
      expr(16);
      break;
    }

    case 5: {
      setState(225);
      match(SQLiteParser::OPEN_PAR);
      setState(226);
      expr(0);
      setState(227);
      match(SQLiteParser::CLOSE_PAR);
      break;
    }

    case 6: {
      setState(229);
      match(SQLiteParser::K_CAST);
      setState(230);
      match(SQLiteParser::OPEN_PAR);
      setState(231);
      expr(0);
      setState(232);
      match(SQLiteParser::K_AS);
      setState(233);
      type_name();
      setState(234);
      match(SQLiteParser::CLOSE_PAR);
      break;
    }

    case 7: {
      setState(240);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLiteParser::K_EXISTS

      || _la == SQLiteParser::K_NOT) {
        setState(237);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLiteParser::K_NOT) {
          setState(236);
          match(SQLiteParser::K_NOT);
        }
        setState(239);
        match(SQLiteParser::K_EXISTS);
      }
      setState(242);
      match(SQLiteParser::OPEN_PAR);
      setState(243);
      select_stmt();
      setState(244);
      match(SQLiteParser::CLOSE_PAR);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(336);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(334);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(248);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(249);
          match(SQLiteParser::PIPE2);
          setState(250);
          expr(16);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(251);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(252);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SQLiteParser::STAR)
            | (1ULL << SQLiteParser::DIV)
            | (1ULL << SQLiteParser::MOD))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(253);
          expr(15);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(254);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(255);
          _la = _input->LA(1);
          if (!(_la == SQLiteParser::PLUS

          || _la == SQLiteParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(256);
          expr(14);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(257);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(258);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SQLiteParser::LT2)
            | (1ULL << SQLiteParser::GT2)
            | (1ULL << SQLiteParser::AMP)
            | (1ULL << SQLiteParser::PIPE))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(259);
          expr(13);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(260);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(261);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SQLiteParser::LT)
            | (1ULL << SQLiteParser::LT_EQ)
            | (1ULL << SQLiteParser::GT)
            | (1ULL << SQLiteParser::GT_EQ))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(262);
          expr(12);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(263);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(272);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case SQLiteParser::ASSIGN: {
              setState(264);
              match(SQLiteParser::ASSIGN);
              break;
            }

            case SQLiteParser::EQ: {
              setState(265);
              match(SQLiteParser::EQ);
              break;
            }

            case SQLiteParser::NOT_EQ1: {
              setState(266);
              match(SQLiteParser::NOT_EQ1);
              break;
            }

            case SQLiteParser::NOT_EQ2: {
              setState(267);
              match(SQLiteParser::NOT_EQ2);
              break;
            }

            case SQLiteParser::K_IS: {
              setState(268);
              match(SQLiteParser::K_IS);
              setState(270);
              _errHandler->sync(this);

              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
              case 1: {
                setState(269);
                match(SQLiteParser::K_NOT);
                break;
              }

              }
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(274);
          expr(11);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(275);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(283);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case SQLiteParser::K_LIKE:
            case SQLiteParser::K_NOT: {
              setState(277);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == SQLiteParser::K_NOT) {
                setState(276);
                match(SQLiteParser::K_NOT);
              }
              setState(279);
              match(SQLiteParser::K_LIKE);
              break;
            }

            case SQLiteParser::K_GLOB: {
              setState(280);
              match(SQLiteParser::K_GLOB);
              break;
            }

            case SQLiteParser::K_MATCH: {
              setState(281);
              match(SQLiteParser::K_MATCH);
              break;
            }

            case SQLiteParser::K_REGEXP: {
              setState(282);
              match(SQLiteParser::K_REGEXP);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(285);
          expr(10);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(286);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(287);
          match(SQLiteParser::K_AND);
          setState(288);
          expr(8);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(289);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(290);
          match(SQLiteParser::K_OR);
          setState(291);
          expr(7);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(292);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(294);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SQLiteParser::K_NOT) {
            setState(293);
            match(SQLiteParser::K_NOT);
          }
          setState(296);
          match(SQLiteParser::K_BETWEEN);
          setState(297);
          expr(0);
          setState(298);
          match(SQLiteParser::K_AND);
          setState(299);
          expr(3);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(301);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(303);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SQLiteParser::K_NOT) {
            setState(302);
            match(SQLiteParser::K_NOT);
          }
          setState(305);
          match(SQLiteParser::K_IN);
          setState(325);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case SQLiteParser::OPEN_PAR: {
              setState(306);
              match(SQLiteParser::OPEN_PAR);
              setState(316);
              _errHandler->sync(this);
              switch (_input->LA(1)) {
                case SQLiteParser::K_SELECT:
                case SQLiteParser::K_VALUES: {
                  setState(307);
                  select_stmt();
                  break;
                }

                case SQLiteParser::OPEN_PAR:
                case SQLiteParser::PLUS:
                case SQLiteParser::MINUS:
                case SQLiteParser::K_CAST:
                case SQLiteParser::K_CURRENT_DATE:
                case SQLiteParser::K_CURRENT_TIME:
                case SQLiteParser::K_CURRENT_TIMESTAMP:
                case SQLiteParser::K_EXISTS:
                case SQLiteParser::K_NOT:
                case SQLiteParser::K_NULL:
                case SQLiteParser::IDENTIFIER:
                case SQLiteParser::NUMERIC_LITERAL:
                case SQLiteParser::STRING_LITERAL:
                case SQLiteParser::BLOB_LITERAL: {
                  setState(308);
                  expr(0);
                  setState(313);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                  while (_la == SQLiteParser::COMMA) {
                    setState(309);
                    match(SQLiteParser::COMMA);
                    setState(310);
                    expr(0);
                    setState(315);
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                  }
                  break;
                }

                case SQLiteParser::CLOSE_PAR: {
                  break;
                }

              default:
                break;
              }
              setState(318);
              match(SQLiteParser::CLOSE_PAR);
              break;
            }

            case SQLiteParser::IDENTIFIER:
            case SQLiteParser::STRING_LITERAL: {
              setState(322);
              _errHandler->sync(this);

              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
              case 1: {
                setState(319);
                database_name();
                setState(320);
                match(SQLiteParser::DOT);
                break;
              }

              }
              setState(324);
              table_name();
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(327);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(332);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case SQLiteParser::K_ISNULL: {
              setState(328);
              match(SQLiteParser::K_ISNULL);
              break;
            }

            case SQLiteParser::K_NOTNULL: {
              setState(329);
              match(SQLiteParser::K_NOTNULL);
              break;
            }

            case SQLiteParser::K_NOT: {
              setState(330);
              match(SQLiteParser::K_NOT);
              setState(331);
              match(SQLiteParser::K_NULL);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        } 
      }
      setState(338);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Ordering_termContext ------------------------------------------------------------------

SQLiteParser::Ordering_termContext::Ordering_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::ExprContext* SQLiteParser::Ordering_termContext::expr() {
  return getRuleContext<SQLiteParser::ExprContext>(0);
}

tree::TerminalNode* SQLiteParser::Ordering_termContext::K_ASC() {
  return getToken(SQLiteParser::K_ASC, 0);
}

tree::TerminalNode* SQLiteParser::Ordering_termContext::K_DESC() {
  return getToken(SQLiteParser::K_DESC, 0);
}


size_t SQLiteParser::Ordering_termContext::getRuleIndex() const {
  return SQLiteParser::RuleOrdering_term;
}


antlrcpp::Any SQLiteParser::Ordering_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitOrdering_term(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Ordering_termContext* SQLiteParser::ordering_term() {
  Ordering_termContext *_localctx = _tracker.createInstance<Ordering_termContext>(_ctx, getState());
  enterRule(_localctx, 18, SQLiteParser::RuleOrdering_term);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    expr(0);
    setState(341);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_ASC

    || _la == SQLiteParser::K_DESC) {
      setState(340);
      _la = _input->LA(1);
      if (!(_la == SQLiteParser::K_ASC

      || _la == SQLiteParser::K_DESC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Result_columnContext ------------------------------------------------------------------

SQLiteParser::Result_columnContext::Result_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Result_columnContext::STAR() {
  return getToken(SQLiteParser::STAR, 0);
}

SQLiteParser::Table_nameContext* SQLiteParser::Result_columnContext::table_name() {
  return getRuleContext<SQLiteParser::Table_nameContext>(0);
}

tree::TerminalNode* SQLiteParser::Result_columnContext::DOT() {
  return getToken(SQLiteParser::DOT, 0);
}

SQLiteParser::ExprContext* SQLiteParser::Result_columnContext::expr() {
  return getRuleContext<SQLiteParser::ExprContext>(0);
}

SQLiteParser::Column_aliasContext* SQLiteParser::Result_columnContext::column_alias() {
  return getRuleContext<SQLiteParser::Column_aliasContext>(0);
}

tree::TerminalNode* SQLiteParser::Result_columnContext::K_AS() {
  return getToken(SQLiteParser::K_AS, 0);
}

tree::TerminalNode* SQLiteParser::Result_columnContext::K_MATCH() {
  return getToken(SQLiteParser::K_MATCH, 0);
}


size_t SQLiteParser::Result_columnContext::getRuleIndex() const {
  return SQLiteParser::RuleResult_column;
}


antlrcpp::Any SQLiteParser::Result_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitResult_column(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Result_columnContext* SQLiteParser::result_column() {
  Result_columnContext *_localctx = _tracker.createInstance<Result_columnContext>(_ctx, getState());
  enterRule(_localctx, 20, SQLiteParser::RuleResult_column);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(356);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(343);
      match(SQLiteParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(344);
      table_name();
      setState(345);
      match(SQLiteParser::DOT);
      setState(346);
      match(SQLiteParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(348);
      expr(0);
      setState(353);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
      case 1: {
        setState(350);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLiteParser::K_AS) {
          setState(349);
          match(SQLiteParser::K_AS);
        }
        setState(352);
        column_alias();
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(355);
      match(SQLiteParser::K_MATCH);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_subqueryContext ------------------------------------------------------------------

SQLiteParser::Table_or_subqueryContext::Table_or_subqueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::Table_nameContext* SQLiteParser::Table_or_subqueryContext::table_name() {
  return getRuleContext<SQLiteParser::Table_nameContext>(0);
}

SQLiteParser::Database_nameContext* SQLiteParser::Table_or_subqueryContext::database_name() {
  return getRuleContext<SQLiteParser::Database_nameContext>(0);
}

tree::TerminalNode* SQLiteParser::Table_or_subqueryContext::DOT() {
  return getToken(SQLiteParser::DOT, 0);
}

SQLiteParser::Table_aliasContext* SQLiteParser::Table_or_subqueryContext::table_alias() {
  return getRuleContext<SQLiteParser::Table_aliasContext>(0);
}

tree::TerminalNode* SQLiteParser::Table_or_subqueryContext::K_AS() {
  return getToken(SQLiteParser::K_AS, 0);
}

tree::TerminalNode* SQLiteParser::Table_or_subqueryContext::OPEN_PAR() {
  return getToken(SQLiteParser::OPEN_PAR, 0);
}

tree::TerminalNode* SQLiteParser::Table_or_subqueryContext::CLOSE_PAR() {
  return getToken(SQLiteParser::CLOSE_PAR, 0);
}

std::vector<SQLiteParser::Table_or_subqueryContext *> SQLiteParser::Table_or_subqueryContext::table_or_subquery() {
  return getRuleContexts<SQLiteParser::Table_or_subqueryContext>();
}

SQLiteParser::Table_or_subqueryContext* SQLiteParser::Table_or_subqueryContext::table_or_subquery(size_t i) {
  return getRuleContext<SQLiteParser::Table_or_subqueryContext>(i);
}

SQLiteParser::Join_clauseContext* SQLiteParser::Table_or_subqueryContext::join_clause() {
  return getRuleContext<SQLiteParser::Join_clauseContext>(0);
}

std::vector<tree::TerminalNode *> SQLiteParser::Table_or_subqueryContext::COMMA() {
  return getTokens(SQLiteParser::COMMA);
}

tree::TerminalNode* SQLiteParser::Table_or_subqueryContext::COMMA(size_t i) {
  return getToken(SQLiteParser::COMMA, i);
}

SQLiteParser::Select_stmtContext* SQLiteParser::Table_or_subqueryContext::select_stmt() {
  return getRuleContext<SQLiteParser::Select_stmtContext>(0);
}


size_t SQLiteParser::Table_or_subqueryContext::getRuleIndex() const {
  return SQLiteParser::RuleTable_or_subquery;
}


antlrcpp::Any SQLiteParser::Table_or_subqueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitTable_or_subquery(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Table_or_subqueryContext* SQLiteParser::table_or_subquery() {
  Table_or_subqueryContext *_localctx = _tracker.createInstance<Table_or_subqueryContext>(_ctx, getState());
  enterRule(_localctx, 22, SQLiteParser::RuleTable_or_subquery);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(361);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
      case 1: {
        setState(358);
        database_name();
        setState(359);
        match(SQLiteParser::DOT);
        break;
      }

      }
      setState(363);
      table_name();
      setState(368);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
      case 1: {
        setState(365);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLiteParser::K_AS) {
          setState(364);
          match(SQLiteParser::K_AS);
        }
        setState(367);
        table_alias();
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(370);
      match(SQLiteParser::OPEN_PAR);
      setState(380);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
      case 1: {
        setState(371);
        table_or_subquery();
        setState(376);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLiteParser::COMMA) {
          setState(372);
          match(SQLiteParser::COMMA);
          setState(373);
          table_or_subquery();
          setState(378);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(379);
        join_clause();
        break;
      }

      }
      setState(382);
      match(SQLiteParser::CLOSE_PAR);
      setState(387);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
      case 1: {
        setState(384);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLiteParser::K_AS) {
          setState(383);
          match(SQLiteParser::K_AS);
        }
        setState(386);
        table_alias();
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(389);
      match(SQLiteParser::OPEN_PAR);
      setState(390);
      select_stmt();
      setState(391);
      match(SQLiteParser::CLOSE_PAR);
      setState(396);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
      case 1: {
        setState(393);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLiteParser::K_AS) {
          setState(392);
          match(SQLiteParser::K_AS);
        }
        setState(395);
        table_alias();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_clauseContext ------------------------------------------------------------------

SQLiteParser::Join_clauseContext::Join_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLiteParser::Table_or_subqueryContext *> SQLiteParser::Join_clauseContext::table_or_subquery() {
  return getRuleContexts<SQLiteParser::Table_or_subqueryContext>();
}

SQLiteParser::Table_or_subqueryContext* SQLiteParser::Join_clauseContext::table_or_subquery(size_t i) {
  return getRuleContext<SQLiteParser::Table_or_subqueryContext>(i);
}

std::vector<SQLiteParser::Join_operatorContext *> SQLiteParser::Join_clauseContext::join_operator() {
  return getRuleContexts<SQLiteParser::Join_operatorContext>();
}

SQLiteParser::Join_operatorContext* SQLiteParser::Join_clauseContext::join_operator(size_t i) {
  return getRuleContext<SQLiteParser::Join_operatorContext>(i);
}

std::vector<SQLiteParser::Join_constraintContext *> SQLiteParser::Join_clauseContext::join_constraint() {
  return getRuleContexts<SQLiteParser::Join_constraintContext>();
}

SQLiteParser::Join_constraintContext* SQLiteParser::Join_clauseContext::join_constraint(size_t i) {
  return getRuleContext<SQLiteParser::Join_constraintContext>(i);
}


size_t SQLiteParser::Join_clauseContext::getRuleIndex() const {
  return SQLiteParser::RuleJoin_clause;
}


antlrcpp::Any SQLiteParser::Join_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitJoin_clause(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Join_clauseContext* SQLiteParser::join_clause() {
  Join_clauseContext *_localctx = _tracker.createInstance<Join_clauseContext>(_ctx, getState());
  enterRule(_localctx, 24, SQLiteParser::RuleJoin_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    table_or_subquery();
    setState(407);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLiteParser::COMMA || ((((_la - 87) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 87)) & ((1ULL << (SQLiteParser::K_INNER - 87))
      | (1ULL << (SQLiteParser::K_JOIN - 87))
      | (1ULL << (SQLiteParser::K_LEFT - 87))
      | (1ULL << (SQLiteParser::K_NATURAL - 87)))) != 0)) {
      setState(401);
      join_operator();
      setState(402);
      table_or_subquery();
      setState(403);
      join_constraint();
      setState(409);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_operatorContext ------------------------------------------------------------------

SQLiteParser::Join_operatorContext::Join_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Join_operatorContext::COMMA() {
  return getToken(SQLiteParser::COMMA, 0);
}

tree::TerminalNode* SQLiteParser::Join_operatorContext::K_JOIN() {
  return getToken(SQLiteParser::K_JOIN, 0);
}

tree::TerminalNode* SQLiteParser::Join_operatorContext::K_NATURAL() {
  return getToken(SQLiteParser::K_NATURAL, 0);
}

tree::TerminalNode* SQLiteParser::Join_operatorContext::K_LEFT() {
  return getToken(SQLiteParser::K_LEFT, 0);
}

tree::TerminalNode* SQLiteParser::Join_operatorContext::K_INNER() {
  return getToken(SQLiteParser::K_INNER, 0);
}

tree::TerminalNode* SQLiteParser::Join_operatorContext::K_OUTER() {
  return getToken(SQLiteParser::K_OUTER, 0);
}


size_t SQLiteParser::Join_operatorContext::getRuleIndex() const {
  return SQLiteParser::RuleJoin_operator;
}


antlrcpp::Any SQLiteParser::Join_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitJoin_operator(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Join_operatorContext* SQLiteParser::join_operator() {
  Join_operatorContext *_localctx = _tracker.createInstance<Join_operatorContext>(_ctx, getState());
  enterRule(_localctx, 26, SQLiteParser::RuleJoin_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(422);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLiteParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(410);
        match(SQLiteParser::COMMA);
        break;
      }

      case SQLiteParser::K_INNER:
      case SQLiteParser::K_JOIN:
      case SQLiteParser::K_LEFT:
      case SQLiteParser::K_NATURAL: {
        enterOuterAlt(_localctx, 2);
        setState(412);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQLiteParser::K_NATURAL) {
          setState(411);
          match(SQLiteParser::K_NATURAL);
        }
        setState(419);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SQLiteParser::K_LEFT: {
            setState(414);
            match(SQLiteParser::K_LEFT);
            setState(416);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == SQLiteParser::K_OUTER) {
              setState(415);
              match(SQLiteParser::K_OUTER);
            }
            break;
          }

          case SQLiteParser::K_INNER: {
            setState(418);
            match(SQLiteParser::K_INNER);
            break;
          }

          case SQLiteParser::K_JOIN: {
            break;
          }

        default:
          break;
        }
        setState(421);
        match(SQLiteParser::K_JOIN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_constraintContext ------------------------------------------------------------------

SQLiteParser::Join_constraintContext::Join_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Join_constraintContext::K_ON() {
  return getToken(SQLiteParser::K_ON, 0);
}

SQLiteParser::ExprContext* SQLiteParser::Join_constraintContext::expr() {
  return getRuleContext<SQLiteParser::ExprContext>(0);
}

tree::TerminalNode* SQLiteParser::Join_constraintContext::K_USING() {
  return getToken(SQLiteParser::K_USING, 0);
}

tree::TerminalNode* SQLiteParser::Join_constraintContext::OPEN_PAR() {
  return getToken(SQLiteParser::OPEN_PAR, 0);
}

std::vector<SQLiteParser::Column_nameContext *> SQLiteParser::Join_constraintContext::column_name() {
  return getRuleContexts<SQLiteParser::Column_nameContext>();
}

SQLiteParser::Column_nameContext* SQLiteParser::Join_constraintContext::column_name(size_t i) {
  return getRuleContext<SQLiteParser::Column_nameContext>(i);
}

tree::TerminalNode* SQLiteParser::Join_constraintContext::CLOSE_PAR() {
  return getToken(SQLiteParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> SQLiteParser::Join_constraintContext::COMMA() {
  return getTokens(SQLiteParser::COMMA);
}

tree::TerminalNode* SQLiteParser::Join_constraintContext::COMMA(size_t i) {
  return getToken(SQLiteParser::COMMA, i);
}


size_t SQLiteParser::Join_constraintContext::getRuleIndex() const {
  return SQLiteParser::RuleJoin_constraint;
}


antlrcpp::Any SQLiteParser::Join_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitJoin_constraint(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Join_constraintContext* SQLiteParser::join_constraint() {
  Join_constraintContext *_localctx = _tracker.createInstance<Join_constraintContext>(_ctx, getState());
  enterRule(_localctx, 28, SQLiteParser::RuleJoin_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLiteParser::K_ON: {
        setState(424);
        match(SQLiteParser::K_ON);
        setState(425);
        expr(0);
        break;
      }

      case SQLiteParser::K_USING: {
        setState(426);
        match(SQLiteParser::K_USING);
        setState(427);
        match(SQLiteParser::OPEN_PAR);
        setState(428);
        column_name();
        setState(433);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLiteParser::COMMA) {
          setState(429);
          match(SQLiteParser::COMMA);
          setState(430);
          column_name();
          setState(435);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(436);
        match(SQLiteParser::CLOSE_PAR);
        break;
      }

      case SQLiteParser::EOF:
      case SQLiteParser::UNSUPPORTED_KEYWORDS:
      case SQLiteParser::SCOL:
      case SQLiteParser::OPEN_PAR:
      case SQLiteParser::CLOSE_PAR:
      case SQLiteParser::COMMA:
      case SQLiteParser::PLUS:
      case SQLiteParser::MINUS:
      case SQLiteParser::K_CAST:
      case SQLiteParser::K_CURRENT_DATE:
      case SQLiteParser::K_CURRENT_TIME:
      case SQLiteParser::K_CURRENT_TIMESTAMP:
      case SQLiteParser::K_EXISTS:
      case SQLiteParser::K_GROUP:
      case SQLiteParser::K_INNER:
      case SQLiteParser::K_JOIN:
      case SQLiteParser::K_LEFT:
      case SQLiteParser::K_LIMIT:
      case SQLiteParser::K_NATURAL:
      case SQLiteParser::K_NOT:
      case SQLiteParser::K_NULL:
      case SQLiteParser::K_ORDER:
      case SQLiteParser::K_SELECT:
      case SQLiteParser::K_UNION:
      case SQLiteParser::K_VALUES:
      case SQLiteParser::K_WHERE:
      case SQLiteParser::IDENTIFIER:
      case SQLiteParser::NUMERIC_LITERAL:
      case SQLiteParser::STRING_LITERAL:
      case SQLiteParser::BLOB_LITERAL:
      case SQLiteParser::UNEXPECTED_CHAR: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_coreContext ------------------------------------------------------------------

SQLiteParser::Select_coreContext::Select_coreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_SELECT() {
  return getToken(SQLiteParser::K_SELECT, 0);
}

std::vector<SQLiteParser::Result_columnContext *> SQLiteParser::Select_coreContext::result_column() {
  return getRuleContexts<SQLiteParser::Result_columnContext>();
}

SQLiteParser::Result_columnContext* SQLiteParser::Select_coreContext::result_column(size_t i) {
  return getRuleContext<SQLiteParser::Result_columnContext>(i);
}

std::vector<tree::TerminalNode *> SQLiteParser::Select_coreContext::COMMA() {
  return getTokens(SQLiteParser::COMMA);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::COMMA(size_t i) {
  return getToken(SQLiteParser::COMMA, i);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_FROM() {
  return getToken(SQLiteParser::K_FROM, 0);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_WHERE() {
  return getToken(SQLiteParser::K_WHERE, 0);
}

std::vector<SQLiteParser::ExprContext *> SQLiteParser::Select_coreContext::expr() {
  return getRuleContexts<SQLiteParser::ExprContext>();
}

SQLiteParser::ExprContext* SQLiteParser::Select_coreContext::expr(size_t i) {
  return getRuleContext<SQLiteParser::ExprContext>(i);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_GROUP() {
  return getToken(SQLiteParser::K_GROUP, 0);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_BY() {
  return getToken(SQLiteParser::K_BY, 0);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_DISTINCT() {
  return getToken(SQLiteParser::K_DISTINCT, 0);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_ALL() {
  return getToken(SQLiteParser::K_ALL, 0);
}

std::vector<SQLiteParser::Table_or_subqueryContext *> SQLiteParser::Select_coreContext::table_or_subquery() {
  return getRuleContexts<SQLiteParser::Table_or_subqueryContext>();
}

SQLiteParser::Table_or_subqueryContext* SQLiteParser::Select_coreContext::table_or_subquery(size_t i) {
  return getRuleContext<SQLiteParser::Table_or_subqueryContext>(i);
}

SQLiteParser::Join_clauseContext* SQLiteParser::Select_coreContext::join_clause() {
  return getRuleContext<SQLiteParser::Join_clauseContext>(0);
}

tree::TerminalNode* SQLiteParser::Select_coreContext::K_HAVING() {
  return getToken(SQLiteParser::K_HAVING, 0);
}


size_t SQLiteParser::Select_coreContext::getRuleIndex() const {
  return SQLiteParser::RuleSelect_core;
}


antlrcpp::Any SQLiteParser::Select_coreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitSelect_core(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Select_coreContext* SQLiteParser::select_core() {
  Select_coreContext *_localctx = _tracker.createInstance<Select_coreContext>(_ctx, getState());
  enterRule(_localctx, 30, SQLiteParser::RuleSelect_core);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    match(SQLiteParser::K_SELECT);
    setState(442);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_ALL

    || _la == SQLiteParser::K_DISTINCT) {
      setState(441);
      _la = _input->LA(1);
      if (!(_la == SQLiteParser::K_ALL

      || _la == SQLiteParser::K_DISTINCT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(444);
    result_column();
    setState(449);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLiteParser::COMMA) {
      setState(445);
      match(SQLiteParser::COMMA);
      setState(446);
      result_column();
      setState(451);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(464);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_FROM) {
      setState(452);
      match(SQLiteParser::K_FROM);
      setState(462);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
      case 1: {
        setState(453);
        table_or_subquery();
        setState(458);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLiteParser::COMMA) {
          setState(454);
          match(SQLiteParser::COMMA);
          setState(455);
          table_or_subquery();
          setState(460);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(461);
        join_clause();
        break;
      }

      }
    }
    setState(468);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_WHERE) {
      setState(466);
      match(SQLiteParser::K_WHERE);
      setState(467);
      expr(0);
    }
    setState(484);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::K_GROUP) {
      setState(470);
      match(SQLiteParser::K_GROUP);
      setState(471);
      match(SQLiteParser::K_BY);
      setState(472);
      expr(0);
      setState(477);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQLiteParser::COMMA) {
        setState(473);
        match(SQLiteParser::COMMA);
        setState(474);
        expr(0);
        setState(479);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(482);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SQLiteParser::K_HAVING) {
        setState(480);
        match(SQLiteParser::K_HAVING);
        setState(481);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_operatorContext ------------------------------------------------------------------

SQLiteParser::Compound_operatorContext::Compound_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Compound_operatorContext::K_UNION() {
  return getToken(SQLiteParser::K_UNION, 0);
}


size_t SQLiteParser::Compound_operatorContext::getRuleIndex() const {
  return SQLiteParser::RuleCompound_operator;
}


antlrcpp::Any SQLiteParser::Compound_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitCompound_operator(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Compound_operatorContext* SQLiteParser::compound_operator() {
  Compound_operatorContext *_localctx = _tracker.createInstance<Compound_operatorContext>(_ctx, getState());
  enterRule(_localctx, 32, SQLiteParser::RuleCompound_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    match(SQLiteParser::K_UNION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signed_numberContext ------------------------------------------------------------------

SQLiteParser::Signed_numberContext::Signed_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Signed_numberContext::NUMERIC_LITERAL() {
  return getToken(SQLiteParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* SQLiteParser::Signed_numberContext::PLUS() {
  return getToken(SQLiteParser::PLUS, 0);
}

tree::TerminalNode* SQLiteParser::Signed_numberContext::MINUS() {
  return getToken(SQLiteParser::MINUS, 0);
}


size_t SQLiteParser::Signed_numberContext::getRuleIndex() const {
  return SQLiteParser::RuleSigned_number;
}


antlrcpp::Any SQLiteParser::Signed_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitSigned_number(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Signed_numberContext* SQLiteParser::signed_number() {
  Signed_numberContext *_localctx = _tracker.createInstance<Signed_numberContext>(_ctx, getState());
  enterRule(_localctx, 34, SQLiteParser::RuleSigned_number);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLiteParser::PLUS

    || _la == SQLiteParser::MINUS) {
      setState(488);
      _la = _input->LA(1);
      if (!(_la == SQLiteParser::PLUS

      || _la == SQLiteParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(491);
    match(SQLiteParser::NUMERIC_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_valueContext ------------------------------------------------------------------

SQLiteParser::Literal_valueContext::Literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Literal_valueContext::NUMERIC_LITERAL() {
  return getToken(SQLiteParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* SQLiteParser::Literal_valueContext::STRING_LITERAL() {
  return getToken(SQLiteParser::STRING_LITERAL, 0);
}

tree::TerminalNode* SQLiteParser::Literal_valueContext::BLOB_LITERAL() {
  return getToken(SQLiteParser::BLOB_LITERAL, 0);
}

tree::TerminalNode* SQLiteParser::Literal_valueContext::K_NULL() {
  return getToken(SQLiteParser::K_NULL, 0);
}

tree::TerminalNode* SQLiteParser::Literal_valueContext::K_CURRENT_TIME() {
  return getToken(SQLiteParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* SQLiteParser::Literal_valueContext::K_CURRENT_DATE() {
  return getToken(SQLiteParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* SQLiteParser::Literal_valueContext::K_CURRENT_TIMESTAMP() {
  return getToken(SQLiteParser::K_CURRENT_TIMESTAMP, 0);
}


size_t SQLiteParser::Literal_valueContext::getRuleIndex() const {
  return SQLiteParser::RuleLiteral_value;
}


antlrcpp::Any SQLiteParser::Literal_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitLiteral_value(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Literal_valueContext* SQLiteParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 36, SQLiteParser::RuleLiteral_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQLiteParser::K_CURRENT_DATE)
      | (1ULL << SQLiteParser::K_CURRENT_TIME)
      | (1ULL << SQLiteParser::K_CURRENT_TIMESTAMP))) != 0) || ((((_la - 103) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 103)) & ((1ULL << (SQLiteParser::K_NULL - 103))
      | (1ULL << (SQLiteParser::NUMERIC_LITERAL - 103))
      | (1ULL << (SQLiteParser::STRING_LITERAL - 103))
      | (1ULL << (SQLiteParser::BLOB_LITERAL - 103)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

SQLiteParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Unary_operatorContext::MINUS() {
  return getToken(SQLiteParser::MINUS, 0);
}

tree::TerminalNode* SQLiteParser::Unary_operatorContext::PLUS() {
  return getToken(SQLiteParser::PLUS, 0);
}

tree::TerminalNode* SQLiteParser::Unary_operatorContext::K_NOT() {
  return getToken(SQLiteParser::K_NOT, 0);
}


size_t SQLiteParser::Unary_operatorContext::getRuleIndex() const {
  return SQLiteParser::RuleUnary_operator;
}


antlrcpp::Any SQLiteParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Unary_operatorContext* SQLiteParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 38, SQLiteParser::RuleUnary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(495);
    _la = _input->LA(1);
    if (!(_la == SQLiteParser::PLUS

    || _la == SQLiteParser::MINUS || _la == SQLiteParser::K_NOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_aliasContext ------------------------------------------------------------------

SQLiteParser::Column_aliasContext::Column_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Column_aliasContext::IDENTIFIER() {
  return getToken(SQLiteParser::IDENTIFIER, 0);
}

tree::TerminalNode* SQLiteParser::Column_aliasContext::STRING_LITERAL() {
  return getToken(SQLiteParser::STRING_LITERAL, 0);
}


size_t SQLiteParser::Column_aliasContext::getRuleIndex() const {
  return SQLiteParser::RuleColumn_alias;
}


antlrcpp::Any SQLiteParser::Column_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitColumn_alias(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Column_aliasContext* SQLiteParser::column_alias() {
  Column_aliasContext *_localctx = _tracker.createInstance<Column_aliasContext>(_ctx, getState());
  enterRule(_localctx, 40, SQLiteParser::RuleColumn_alias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
    _la = _input->LA(1);
    if (!(_la == SQLiteParser::IDENTIFIER

    || _la == SQLiteParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

SQLiteParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ADD() {
  return getToken(SQLiteParser::K_ADD, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_AFTER() {
  return getToken(SQLiteParser::K_AFTER, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ALL() {
  return getToken(SQLiteParser::K_ALL, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_AND() {
  return getToken(SQLiteParser::K_AND, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_AS() {
  return getToken(SQLiteParser::K_AS, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ASC() {
  return getToken(SQLiteParser::K_ASC, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_BEFORE() {
  return getToken(SQLiteParser::K_BEFORE, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_BETWEEN() {
  return getToken(SQLiteParser::K_BETWEEN, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_BY() {
  return getToken(SQLiteParser::K_BY, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_CAST() {
  return getToken(SQLiteParser::K_CAST, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_COLUMN() {
  return getToken(SQLiteParser::K_COLUMN, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_CURRENT_DATE() {
  return getToken(SQLiteParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_CURRENT_TIME() {
  return getToken(SQLiteParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_CURRENT_TIMESTAMP() {
  return getToken(SQLiteParser::K_CURRENT_TIMESTAMP, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_DATABASE() {
  return getToken(SQLiteParser::K_DATABASE, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_DEFAULT() {
  return getToken(SQLiteParser::K_DEFAULT, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_DESC() {
  return getToken(SQLiteParser::K_DESC, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_DISTINCT() {
  return getToken(SQLiteParser::K_DISTINCT, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ELSE() {
  return getToken(SQLiteParser::K_ELSE, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_END() {
  return getToken(SQLiteParser::K_END, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ESCAPE() {
  return getToken(SQLiteParser::K_ESCAPE, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_EXISTS() {
  return getToken(SQLiteParser::K_EXISTS, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_EXPLAIN() {
  return getToken(SQLiteParser::K_EXPLAIN, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_FAIL() {
  return getToken(SQLiteParser::K_FAIL, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_FOR() {
  return getToken(SQLiteParser::K_FOR, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_FROM() {
  return getToken(SQLiteParser::K_FROM, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_GLOB() {
  return getToken(SQLiteParser::K_GLOB, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_GROUP() {
  return getToken(SQLiteParser::K_GROUP, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_HAVING() {
  return getToken(SQLiteParser::K_HAVING, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_IN() {
  return getToken(SQLiteParser::K_IN, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_INNER() {
  return getToken(SQLiteParser::K_INNER, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_INTO() {
  return getToken(SQLiteParser::K_INTO, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_IS() {
  return getToken(SQLiteParser::K_IS, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ISNULL() {
  return getToken(SQLiteParser::K_ISNULL, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_JOIN() {
  return getToken(SQLiteParser::K_JOIN, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_LEFT() {
  return getToken(SQLiteParser::K_LEFT, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_LIKE() {
  return getToken(SQLiteParser::K_LIKE, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_LIMIT() {
  return getToken(SQLiteParser::K_LIMIT, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_MATCH() {
  return getToken(SQLiteParser::K_MATCH, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_NATURAL() {
  return getToken(SQLiteParser::K_NATURAL, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_NO() {
  return getToken(SQLiteParser::K_NO, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_NOT() {
  return getToken(SQLiteParser::K_NOT, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_NOTNULL() {
  return getToken(SQLiteParser::K_NOTNULL, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_OF() {
  return getToken(SQLiteParser::K_OF, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_OFFSET() {
  return getToken(SQLiteParser::K_OFFSET, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ON() {
  return getToken(SQLiteParser::K_ON, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_OR() {
  return getToken(SQLiteParser::K_OR, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ORDER() {
  return getToken(SQLiteParser::K_ORDER, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_OUTER() {
  return getToken(SQLiteParser::K_OUTER, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_REGEXP() {
  return getToken(SQLiteParser::K_REGEXP, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_RIGHT() {
  return getToken(SQLiteParser::K_RIGHT, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_ROW() {
  return getToken(SQLiteParser::K_ROW, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_SELECT() {
  return getToken(SQLiteParser::K_SELECT, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_UNIQUE() {
  return getToken(SQLiteParser::K_UNIQUE, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_UNION() {
  return getToken(SQLiteParser::K_UNION, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_USING() {
  return getToken(SQLiteParser::K_USING, 0);
}

tree::TerminalNode* SQLiteParser::KeywordContext::K_WHERE() {
  return getToken(SQLiteParser::K_WHERE, 0);
}


size_t SQLiteParser::KeywordContext::getRuleIndex() const {
  return SQLiteParser::RuleKeyword;
}


antlrcpp::Any SQLiteParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::KeywordContext* SQLiteParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 42, SQLiteParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    _la = _input->LA(1);
    if (!(((((_la - 27) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 27)) & ((1ULL << (SQLiteParser::K_ADD - 27))
      | (1ULL << (SQLiteParser::K_AFTER - 27))
      | (1ULL << (SQLiteParser::K_ALL - 27))
      | (1ULL << (SQLiteParser::K_AND - 27))
      | (1ULL << (SQLiteParser::K_AS - 27))
      | (1ULL << (SQLiteParser::K_ASC - 27))
      | (1ULL << (SQLiteParser::K_BEFORE - 27))
      | (1ULL << (SQLiteParser::K_BETWEEN - 27))
      | (1ULL << (SQLiteParser::K_BY - 27))
      | (1ULL << (SQLiteParser::K_CAST - 27))
      | (1ULL << (SQLiteParser::K_COLUMN - 27))
      | (1ULL << (SQLiteParser::K_CURRENT_DATE - 27))
      | (1ULL << (SQLiteParser::K_CURRENT_TIME - 27))
      | (1ULL << (SQLiteParser::K_CURRENT_TIMESTAMP - 27))
      | (1ULL << (SQLiteParser::K_DATABASE - 27))
      | (1ULL << (SQLiteParser::K_DEFAULT - 27))
      | (1ULL << (SQLiteParser::K_DESC - 27))
      | (1ULL << (SQLiteParser::K_DISTINCT - 27))
      | (1ULL << (SQLiteParser::K_ELSE - 27))
      | (1ULL << (SQLiteParser::K_END - 27))
      | (1ULL << (SQLiteParser::K_ESCAPE - 27))
      | (1ULL << (SQLiteParser::K_EXISTS - 27))
      | (1ULL << (SQLiteParser::K_EXPLAIN - 27))
      | (1ULL << (SQLiteParser::K_FAIL - 27))
      | (1ULL << (SQLiteParser::K_FOR - 27))
      | (1ULL << (SQLiteParser::K_FROM - 27))
      | (1ULL << (SQLiteParser::K_GLOB - 27))
      | (1ULL << (SQLiteParser::K_GROUP - 27))
      | (1ULL << (SQLiteParser::K_HAVING - 27))
      | (1ULL << (SQLiteParser::K_IN - 27))
      | (1ULL << (SQLiteParser::K_INNER - 27)))) != 0) || ((((_la - 91) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 91)) & ((1ULL << (SQLiteParser::K_INTO - 91))
      | (1ULL << (SQLiteParser::K_IS - 91))
      | (1ULL << (SQLiteParser::K_ISNULL - 91))
      | (1ULL << (SQLiteParser::K_JOIN - 91))
      | (1ULL << (SQLiteParser::K_LEFT - 91))
      | (1ULL << (SQLiteParser::K_LIKE - 91))
      | (1ULL << (SQLiteParser::K_LIMIT - 91))
      | (1ULL << (SQLiteParser::K_MATCH - 91))
      | (1ULL << (SQLiteParser::K_NATURAL - 91))
      | (1ULL << (SQLiteParser::K_NO - 91))
      | (1ULL << (SQLiteParser::K_NOT - 91))
      | (1ULL << (SQLiteParser::K_NOTNULL - 91))
      | (1ULL << (SQLiteParser::K_OF - 91))
      | (1ULL << (SQLiteParser::K_OFFSET - 91))
      | (1ULL << (SQLiteParser::K_ON - 91))
      | (1ULL << (SQLiteParser::K_OR - 91))
      | (1ULL << (SQLiteParser::K_ORDER - 91))
      | (1ULL << (SQLiteParser::K_OUTER - 91))
      | (1ULL << (SQLiteParser::K_REGEXP - 91))
      | (1ULL << (SQLiteParser::K_RIGHT - 91))
      | (1ULL << (SQLiteParser::K_ROW - 91))
      | (1ULL << (SQLiteParser::K_SELECT - 91))
      | (1ULL << (SQLiteParser::K_UNION - 91))
      | (1ULL << (SQLiteParser::K_UNIQUE - 91))
      | (1ULL << (SQLiteParser::K_USING - 91))
      | (1ULL << (SQLiteParser::K_WHERE - 91)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

SQLiteParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLiteParser::Any_nameContext* SQLiteParser::NameContext::any_name() {
  return getRuleContext<SQLiteParser::Any_nameContext>(0);
}


size_t SQLiteParser::NameContext::getRuleIndex() const {
  return SQLiteParser::RuleName;
}


antlrcpp::Any SQLiteParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::NameContext* SQLiteParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 44, SQLiteParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

SQLiteParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Function_nameContext::IDENTIFIER() {
  return getToken(SQLiteParser::IDENTIFIER, 0);
}


size_t SQLiteParser::Function_nameContext::getRuleIndex() const {
  return SQLiteParser::RuleFunction_name;
}


antlrcpp::Any SQLiteParser::Function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitFunction_name(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Function_nameContext* SQLiteParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 46, SQLiteParser::RuleFunction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    match(SQLiteParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Database_nameContext ------------------------------------------------------------------

SQLiteParser::Database_nameContext::Database_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Database_nameContext::IDENTIFIER() {
  return getToken(SQLiteParser::IDENTIFIER, 0);
}

tree::TerminalNode* SQLiteParser::Database_nameContext::STRING_LITERAL() {
  return getToken(SQLiteParser::STRING_LITERAL, 0);
}


size_t SQLiteParser::Database_nameContext::getRuleIndex() const {
  return SQLiteParser::RuleDatabase_name;
}


antlrcpp::Any SQLiteParser::Database_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitDatabase_name(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Database_nameContext* SQLiteParser::database_name() {
  Database_nameContext *_localctx = _tracker.createInstance<Database_nameContext>(_ctx, getState());
  enterRule(_localctx, 48, SQLiteParser::RuleDatabase_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
    _la = _input->LA(1);
    if (!(_la == SQLiteParser::IDENTIFIER

    || _la == SQLiteParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

SQLiteParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Table_nameContext::IDENTIFIER() {
  return getToken(SQLiteParser::IDENTIFIER, 0);
}

tree::TerminalNode* SQLiteParser::Table_nameContext::STRING_LITERAL() {
  return getToken(SQLiteParser::STRING_LITERAL, 0);
}


size_t SQLiteParser::Table_nameContext::getRuleIndex() const {
  return SQLiteParser::RuleTable_name;
}


antlrcpp::Any SQLiteParser::Table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitTable_name(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Table_nameContext* SQLiteParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 50, SQLiteParser::RuleTable_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    _la = _input->LA(1);
    if (!(_la == SQLiteParser::IDENTIFIER

    || _la == SQLiteParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_nameContext ------------------------------------------------------------------

SQLiteParser::Column_nameContext::Column_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Column_nameContext::IDENTIFIER() {
  return getToken(SQLiteParser::IDENTIFIER, 0);
}

tree::TerminalNode* SQLiteParser::Column_nameContext::STRING_LITERAL() {
  return getToken(SQLiteParser::STRING_LITERAL, 0);
}


size_t SQLiteParser::Column_nameContext::getRuleIndex() const {
  return SQLiteParser::RuleColumn_name;
}


antlrcpp::Any SQLiteParser::Column_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitColumn_name(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Column_nameContext* SQLiteParser::column_name() {
  Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
  enterRule(_localctx, 52, SQLiteParser::RuleColumn_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    _la = _input->LA(1);
    if (!(_la == SQLiteParser::IDENTIFIER

    || _la == SQLiteParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_aliasContext ------------------------------------------------------------------

SQLiteParser::Table_aliasContext::Table_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Table_aliasContext::IDENTIFIER() {
  return getToken(SQLiteParser::IDENTIFIER, 0);
}

tree::TerminalNode* SQLiteParser::Table_aliasContext::STRING_LITERAL() {
  return getToken(SQLiteParser::STRING_LITERAL, 0);
}


size_t SQLiteParser::Table_aliasContext::getRuleIndex() const {
  return SQLiteParser::RuleTable_alias;
}


antlrcpp::Any SQLiteParser::Table_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitTable_alias(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Table_aliasContext* SQLiteParser::table_alias() {
  Table_aliasContext *_localctx = _tracker.createInstance<Table_aliasContext>(_ctx, getState());
  enterRule(_localctx, 54, SQLiteParser::RuleTable_alias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    _la = _input->LA(1);
    if (!(_la == SQLiteParser::IDENTIFIER

    || _la == SQLiteParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_nameContext ------------------------------------------------------------------

SQLiteParser::Any_nameContext::Any_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLiteParser::Any_nameContext::IDENTIFIER() {
  return getToken(SQLiteParser::IDENTIFIER, 0);
}

SQLiteParser::KeywordContext* SQLiteParser::Any_nameContext::keyword() {
  return getRuleContext<SQLiteParser::KeywordContext>(0);
}

tree::TerminalNode* SQLiteParser::Any_nameContext::STRING_LITERAL() {
  return getToken(SQLiteParser::STRING_LITERAL, 0);
}

tree::TerminalNode* SQLiteParser::Any_nameContext::OPEN_PAR() {
  return getToken(SQLiteParser::OPEN_PAR, 0);
}

SQLiteParser::Any_nameContext* SQLiteParser::Any_nameContext::any_name() {
  return getRuleContext<SQLiteParser::Any_nameContext>(0);
}

tree::TerminalNode* SQLiteParser::Any_nameContext::CLOSE_PAR() {
  return getToken(SQLiteParser::CLOSE_PAR, 0);
}


size_t SQLiteParser::Any_nameContext::getRuleIndex() const {
  return SQLiteParser::RuleAny_name;
}


antlrcpp::Any SQLiteParser::Any_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLiteVisitor*>(visitor))
    return parserVisitor->visitAny_name(this);
  else
    return visitor->visitChildren(this);
}

SQLiteParser::Any_nameContext* SQLiteParser::any_name() {
  Any_nameContext *_localctx = _tracker.createInstance<Any_nameContext>(_ctx, getState());
  enterRule(_localctx, 56, SQLiteParser::RuleAny_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(520);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLiteParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(513);
        match(SQLiteParser::IDENTIFIER);
        break;
      }

      case SQLiteParser::K_ADD:
      case SQLiteParser::K_AFTER:
      case SQLiteParser::K_ALL:
      case SQLiteParser::K_AND:
      case SQLiteParser::K_AS:
      case SQLiteParser::K_ASC:
      case SQLiteParser::K_BEFORE:
      case SQLiteParser::K_BETWEEN:
      case SQLiteParser::K_BY:
      case SQLiteParser::K_CAST:
      case SQLiteParser::K_COLUMN:
      case SQLiteParser::K_CURRENT_DATE:
      case SQLiteParser::K_CURRENT_TIME:
      case SQLiteParser::K_CURRENT_TIMESTAMP:
      case SQLiteParser::K_DATABASE:
      case SQLiteParser::K_DEFAULT:
      case SQLiteParser::K_DESC:
      case SQLiteParser::K_DISTINCT:
      case SQLiteParser::K_ELSE:
      case SQLiteParser::K_END:
      case SQLiteParser::K_ESCAPE:
      case SQLiteParser::K_EXISTS:
      case SQLiteParser::K_EXPLAIN:
      case SQLiteParser::K_FAIL:
      case SQLiteParser::K_FOR:
      case SQLiteParser::K_FROM:
      case SQLiteParser::K_GLOB:
      case SQLiteParser::K_GROUP:
      case SQLiteParser::K_HAVING:
      case SQLiteParser::K_IN:
      case SQLiteParser::K_INNER:
      case SQLiteParser::K_INTO:
      case SQLiteParser::K_IS:
      case SQLiteParser::K_ISNULL:
      case SQLiteParser::K_JOIN:
      case SQLiteParser::K_LEFT:
      case SQLiteParser::K_LIKE:
      case SQLiteParser::K_LIMIT:
      case SQLiteParser::K_MATCH:
      case SQLiteParser::K_NATURAL:
      case SQLiteParser::K_NO:
      case SQLiteParser::K_NOT:
      case SQLiteParser::K_NOTNULL:
      case SQLiteParser::K_OF:
      case SQLiteParser::K_OFFSET:
      case SQLiteParser::K_ON:
      case SQLiteParser::K_OR:
      case SQLiteParser::K_ORDER:
      case SQLiteParser::K_OUTER:
      case SQLiteParser::K_REGEXP:
      case SQLiteParser::K_RIGHT:
      case SQLiteParser::K_ROW:
      case SQLiteParser::K_SELECT:
      case SQLiteParser::K_UNION:
      case SQLiteParser::K_UNIQUE:
      case SQLiteParser::K_USING:
      case SQLiteParser::K_WHERE: {
        enterOuterAlt(_localctx, 2);
        setState(514);
        keyword();
        break;
      }

      case SQLiteParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(515);
        match(SQLiteParser::STRING_LITERAL);
        break;
      }

      case SQLiteParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(516);
        match(SQLiteParser::OPEN_PAR);
        setState(517);
        any_name();
        setState(518);
        match(SQLiteParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SQLiteParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SQLiteParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 15);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 7);
    case 8: return precpred(_ctx, 6);
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 8);
    case 11: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SQLiteParser::_decisionToDFA;
atn::PredictionContextCache SQLiteParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SQLiteParser::_atn;
std::vector<uint16_t> SQLiteParser::_serializedATN;

std::vector<std::string> SQLiteParser::_ruleNames = {
  "parse", "error", "sql_stmt_or_expr", "sql_stmt", "simple_select_stmt", 
  "select_stmt", "select_or_values", "type_name", "expr", "ordering_term", 
  "result_column", "table_or_subquery", "join_clause", "join_operator", 
  "join_constraint", "select_core", "compound_operator", "signed_number", 
  "literal_value", "unary_operator", "column_alias", "keyword", "name", 
  "function_name", "database_name", "table_name", "column_name", "table_alias", 
  "any_name"
};

std::vector<std::string> SQLiteParser::_literalNames = {
  "", "", "';'", "'.'", "'('", "')'", "','", "'='", "'*'", "'+'", "'-'", 
  "'~'", "'||'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", "'<='", 
  "'>'", "'>='", "'=='", "'!='", "'<>'"
};

std::vector<std::string> SQLiteParser::_symbolicNames = {
  "", "UNSUPPORTED_KEYWORDS", "SCOL", "DOT", "OPEN_PAR", "CLOSE_PAR", "COMMA", 
  "ASSIGN", "STAR", "PLUS", "MINUS", "TILDE", "PIPE2", "DIV", "MOD", "LT2", 
  "GT2", "AMP", "PIPE", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NOT_EQ1", "NOT_EQ2", 
  "K_ABORT", "K_ADD", "K_AFTER", "K_ALL", "K_ALTER", "K_ANALYZE", "K_AND", 
  "K_AS", "K_ASC", "K_ATTACH", "K_AUTOINCREMENT", "K_BEFORE", "K_BEGIN", 
  "K_BETWEEN", "K_BY", "K_CASCADE", "K_CASE", "K_CAST", "K_CHECK", "K_COLLATE", 
  "K_COLUMN", "K_COMMIT", "K_CONFLICT", "K_CONSTRAINT", "K_CREATE", "K_CROSS", 
  "K_CURRENT_DATE", "K_CURRENT_TIME", "K_CURRENT_TIMESTAMP", "K_DATABASE", 
  "K_DEFAULT", "K_DEFERRABLE", "K_DEFERRED", "K_DELETE", "K_DESC", "K_DETACH", 
  "K_DISTINCT", "K_DROP", "K_EACH", "K_ELSE", "K_END", "K_ESCAPE", "K_EXCEPT", 
  "K_EXCLUSIVE", "K_EXISTS", "K_EXPLAIN", "K_FAIL", "K_FOR", "K_FOREIGN", 
  "K_FROM", "K_FULL", "K_GLOB", "K_GROUP", "K_HAVING", "K_IF", "K_IGNORE", 
  "K_IMMEDIATE", "K_IN", "K_INDEX", "K_INDEXED", "K_INITIALLY", "K_INNER", 
  "K_INSERT", "K_INSTEAD", "K_INTERSECT", "K_INTO", "K_IS", "K_ISNULL", 
  "K_JOIN", "K_LEFT", "K_LIKE", "K_LIMIT", "K_MATCH", "K_NATURAL", "K_NO", 
  "K_NOT", "K_NOTNULL", "K_NULL", "K_OF", "K_OFFSET", "K_ON", "K_OR", "K_ORDER", 
  "K_OUTER", "K_PLAN", "K_PRAGMA", "K_PRIMARY", "K_RAISE", "K_RECURSIVE", 
  "K_REFERENCES", "K_REGEXP", "K_REINDEX", "K_RELEASE", "K_RENAME", "K_REPLACE", 
  "K_RESTRICT", "K_RIGHT", "K_ROLLBACK", "K_ROW", "K_SAVEPOINT", "K_SELECT", 
  "K_SET", "K_TABLE", "K_TEMP", "K_TEMPORARY", "K_THEN", "K_TO", "K_TRANSACTION", 
  "K_TRIGGER", "K_UNION", "K_UNIQUE", "K_UPDATE", "K_USING", "K_VACUUM", 
  "K_VALUES", "K_VIEW", "K_VIRTUAL", "K_WHEN", "K_WHERE", "K_WITH", "K_WITHOUT", 
  "IDENTIFIER", "UNQUOTED_IDENTIFIER", "NUMERIC_LITERAL", "BIND_PARAMETER", 
  "STRING_LITERAL", "BLOB_LITERAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", 
  "SPACES", "UNEXPECTED_CHAR"
};

dfa::Vocabulary SQLiteParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SQLiteParser::_tokenNames;

SQLiteParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x9e, 0x20d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x3f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x42, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x4a, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4e, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0x52, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x55, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x59, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x5c, 0xb, 0x5, 0x5, 0x5, 0x5e, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x66, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x69, 0xb, 0x6, 0x5, 0x6, 0x6b, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x71, 0xa, 0x6, 0x5, 0x6, 0x73, 0xa, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x79, 0xa, 0x7, 0xc, 0x7, 
    0xe, 0x7, 0x7c, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0x83, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x86, 0xb, 0x7, 0x5, 
    0x7, 0x88, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0x8e, 0xa, 0x7, 0x5, 0x7, 0x90, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x98, 0xa, 0x8, 0xc, 0x8, 0xe, 
    0x8, 0x9b, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0xa3, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xa6, 0xb, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xaa, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xad, 
    0xb, 0x8, 0x5, 0x8, 0xaf, 0xa, 0x8, 0x3, 0x9, 0x6, 0x9, 0xb2, 0xa, 0x9, 
    0xd, 0x9, 0xe, 0x9, 0xb3, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xc0, 
    0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0xc7, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xcc, 0xa, 0xa, 
    0xc, 0xa, 0xe, 0xa, 0xcf, 0xb, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd2, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd9, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xde, 0xa, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0xf0, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0xf3, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xf9, 0xa, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x111, 0xa, 0xa, 0x5, 0xa, 0x113, 0xa, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x118, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x11e, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x129, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x132, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x13a, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0x13d, 0xb, 0xa, 0x5, 0xa, 0x13f, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x145, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0x148, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x14f, 0xa, 0xa, 0x7, 0xa, 0x151, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x154, 
    0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x158, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x161, 
    0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0x164, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0x167, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x16c, 0xa, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0x170, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x173, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x179, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x17c, 0xb, 0xd, 0x3, 0xd, 0x5, 0xd, 0x17f, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x183, 0xa, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x186, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0x18c, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0x18f, 0xa, 0xd, 0x5, 0xd, 0x191, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 
    0x198, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x19b, 0xb, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0x19f, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1a3, 
    0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1a6, 0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1a9, 
    0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x7, 0x10, 0x1b2, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0x1b5, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1b9, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x1bd, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x1c2, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1c5, 
    0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x1cb, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1ce, 0xb, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x1d1, 0xa, 0x11, 0x5, 0x11, 0x1d3, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x1d7, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x1de, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1e1, 
    0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x1e5, 0xa, 0x11, 0x5, 0x11, 
    0x1e7, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x5, 0x13, 0x1ec, 
    0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x20b, 0xa, 0x1e, 
    0x3, 0x1e, 0x2, 0x3, 0x12, 0x1f, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x2, 0xd, 
    0x4, 0x2, 0x8, 0x8, 0x6b, 0x6b, 0x4, 0x2, 0xa, 0xa, 0xf, 0x10, 0x3, 
    0x2, 0xb, 0xc, 0x3, 0x2, 0x11, 0x14, 0x3, 0x2, 0x15, 0x18, 0x4, 0x2, 
    0x24, 0x24, 0x3e, 0x3e, 0x4, 0x2, 0x1f, 0x1f, 0x40, 0x40, 0x6, 0x2, 
    0x36, 0x38, 0x69, 0x69, 0x97, 0x97, 0x99, 0x9a, 0x4, 0x2, 0xb, 0xc, 
    0x67, 0x67, 0x4, 0x2, 0x95, 0x95, 0x99, 0x99, 0x1a, 0x2, 0x1d, 0x1f, 
    0x22, 0x24, 0x27, 0x27, 0x29, 0x2a, 0x2d, 0x2d, 0x30, 0x30, 0x36, 0x3a, 
    0x3e, 0x3e, 0x40, 0x40, 0x43, 0x45, 0x48, 0x4b, 0x4d, 0x4d, 0x4f, 0x51, 
    0x55, 0x55, 0x59, 0x59, 0x5d, 0x68, 0x6a, 0x6f, 0x76, 0x76, 0x7c, 0x7c, 
    0x7e, 0x7e, 0x80, 0x80, 0x89, 0x8a, 0x8c, 0x8c, 0x92, 0x92, 0x2, 0x259, 
    0x2, 0x40, 0x3, 0x2, 0x2, 0x2, 0x4, 0x49, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x74, 0x3, 0x2, 0x2, 0x2, 0xe, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x12, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x155, 0x3, 0x2, 0x2, 0x2, 0x16, 0x166, 0x3, 0x2, 0x2, 0x2, 0x18, 0x190, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x192, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a8, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1ba, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1eb, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x1f7, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x32, 0x1fb, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1ff, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x201, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x20a, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3f, 0x5, 0x6, 0x4, 0x2, 0x3d, 0x3f, 0x5, 0x4, 0x3, 
    0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x2, 0x2, 0x3, 0x44, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x9e, 0x2, 0x2, 0x46, 0x4a, 0x8, 0x3, 
    0x1, 0x2, 0x47, 0x48, 0x7, 0x3, 0x2, 0x2, 0x48, 0x4a, 0x8, 0x3, 0x1, 
    0x2, 0x49, 0x45, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 0x5, 0x8, 0x5, 0x2, 0x4c, 
    0x4e, 0x5, 0x12, 0xa, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x53, 0x5, 
    0xa, 0x6, 0x2, 0x50, 0x52, 0x7, 0x4, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x55, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x5e, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5a, 0x5, 0xc, 0x7, 0x2, 0x57, 
    0x59, 0x7, 0x4, 0x2, 0x2, 0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x6a, 0x5, 0x20, 0x11, 0x2, 
    0x60, 0x61, 0x7, 0x6e, 0x2, 0x2, 0x61, 0x62, 0x7, 0x2a, 0x2, 0x2, 0x62, 
    0x67, 0x5, 0x14, 0xb, 0x2, 0x63, 0x64, 0x7, 0x8, 0x2, 0x2, 0x64, 0x66, 
    0x5, 0x14, 0xb, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x60, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x72, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x63, 0x2, 0x2, 0x6d, 
    0x70, 0x5, 0x12, 0xa, 0x2, 0x6e, 0x6f, 0x9, 0x2, 0x2, 0x2, 0x6f, 0x71, 
    0x5, 0x12, 0xa, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x7a, 0x5, 0xe, 0x8, 0x2, 0x75, 0x76, 0x5, 0x22, 0x12, 0x2, 
    0x76, 0x77, 0x5, 0xe, 0x8, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x6e, 
    0x2, 0x2, 0x7e, 0x7f, 0x7, 0x2a, 0x2, 0x2, 0x7f, 0x84, 0x5, 0x14, 0xb, 
    0x2, 0x80, 0x81, 0x7, 0x8, 0x2, 0x2, 0x81, 0x83, 0x5, 0x14, 0xb, 0x2, 
    0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8a, 0x7, 0x63, 0x2, 0x2, 0x8a, 0x8d, 0x5, 0x12, 0xa, 
    0x2, 0x8b, 0x8c, 0x9, 0x2, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0x12, 0xa, 0x2, 
    0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0xd, 0x3, 0x2, 0x2, 0x2, 0x91, 0xaf, 0x5, 
    0x20, 0x11, 0x2, 0x92, 0x93, 0x7, 0x8e, 0x2, 0x2, 0x93, 0x94, 0x7, 0x6, 
    0x2, 0x2, 0x94, 0x99, 0x5, 0x12, 0xa, 0x2, 0x95, 0x96, 0x7, 0x8, 0x2, 
    0x2, 0x96, 0x98, 0x5, 0x12, 0xa, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0xab, 0x7, 0x7, 0x2, 0x2, 0x9d, 0x9e, 0x7, 
    0x8, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x6, 0x2, 0x2, 0x9f, 0xa4, 0x5, 0x12, 
    0xa, 0x2, 0xa0, 0xa1, 0x7, 0x8, 0x2, 0x2, 0xa1, 0xa3, 0x5, 0x12, 0xa, 
    0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 
    0x7, 0x7, 0x2, 0x2, 0xa8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0x92, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xb2, 0x5, 0x2e, 0x18, 0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x6, 
    0x2, 0x2, 0xb6, 0xb7, 0x5, 0x24, 0x13, 0x2, 0xb7, 0xb8, 0x7, 0x7, 0x2, 
    0x2, 0xb8, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x6, 0x2, 0x2, 
    0xba, 0xbb, 0x5, 0x24, 0x13, 0x2, 0xbb, 0xbc, 0x7, 0x8, 0x2, 0x2, 0xbc, 
    0xbd, 0x5, 0x24, 0x13, 0x2, 0xbd, 0xbe, 0x7, 0x7, 0x2, 0x2, 0xbe, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xc2, 0x8, 0xa, 0x1, 0x2, 0xc2, 0xf9, 0x5, 0x26, 0x14, 
    0x2, 0xc3, 0xc4, 0x5, 0x30, 0x19, 0x2, 0xc4, 0xd1, 0x7, 0x6, 0x2, 0x2, 
    0xc5, 0xc7, 0x7, 0x40, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcd, 
    0x5, 0x12, 0xa, 0x2, 0xc9, 0xca, 0x7, 0x8, 0x2, 0x2, 0xca, 0xcc, 0x5, 
    0x12, 0xa, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xd2, 0x7, 0xa, 0x2, 0x2, 0xd1, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x7, 0x2, 0x2, 0xd4, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x32, 0x1a, 0x2, 0xd6, 0xd7, 0x7, 0x5, 
    0x2, 0x2, 0xd7, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xdb, 0x5, 0x34, 0x1b, 0x2, 0xdb, 0xdc, 0x7, 0x5, 0x2, 0x2, 0xdc, 
    0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xf9, 0x5, 
    0x36, 0x1c, 0x2, 0xe0, 0xe1, 0x5, 0x28, 0x15, 0x2, 0xe1, 0xe2, 0x5, 
    0x12, 0xa, 0x12, 0xe2, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x6, 
    0x2, 0x2, 0xe4, 0xe5, 0x5, 0x12, 0xa, 0x2, 0xe5, 0xe6, 0x7, 0x7, 0x2, 
    0x2, 0xe6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x2d, 0x2, 0x2, 
    0xe8, 0xe9, 0x7, 0x6, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x12, 0xa, 0x2, 0xea, 
    0xeb, 0x7, 0x23, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x10, 0x9, 0x2, 0xec, 0xed, 
    0x7, 0x7, 0x2, 0x2, 0xed, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x7, 
    0x67, 0x2, 0x2, 0xef, 0xee, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf3, 0x7, 0x48, 0x2, 
    0x2, 0xf2, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x6, 0x2, 0x2, 0xf5, 
    0xf6, 0x5, 0xc, 0x7, 0x2, 0xf6, 0xf7, 0x7, 0x7, 0x2, 0x2, 0xf7, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xf8, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xe0, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xe7, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf9, 0x152, 0x3, 0x2, 0x2, 0x2, 
    0xfa, 0xfb, 0xc, 0x11, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0xe, 0x2, 0x2, 0xfc, 
    0x151, 0x5, 0x12, 0xa, 0x12, 0xfd, 0xfe, 0xc, 0x10, 0x2, 0x2, 0xfe, 
    0xff, 0x9, 0x3, 0x2, 0x2, 0xff, 0x151, 0x5, 0x12, 0xa, 0x11, 0x100, 
    0x101, 0xc, 0xf, 0x2, 0x2, 0x101, 0x102, 0x9, 0x4, 0x2, 0x2, 0x102, 
    0x151, 0x5, 0x12, 0xa, 0x10, 0x103, 0x104, 0xc, 0xe, 0x2, 0x2, 0x104, 
    0x105, 0x9, 0x5, 0x2, 0x2, 0x105, 0x151, 0x5, 0x12, 0xa, 0xf, 0x106, 
    0x107, 0xc, 0xd, 0x2, 0x2, 0x107, 0x108, 0x9, 0x6, 0x2, 0x2, 0x108, 
    0x151, 0x5, 0x12, 0xa, 0xe, 0x109, 0x112, 0xc, 0xc, 0x2, 0x2, 0x10a, 
    0x113, 0x7, 0x9, 0x2, 0x2, 0x10b, 0x113, 0x7, 0x19, 0x2, 0x2, 0x10c, 
    0x113, 0x7, 0x1a, 0x2, 0x2, 0x10d, 0x113, 0x7, 0x1b, 0x2, 0x2, 0x10e, 
    0x110, 0x7, 0x5e, 0x2, 0x2, 0x10f, 0x111, 0x7, 0x67, 0x2, 0x2, 0x110, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x112, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x112, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x151, 0x5, 0x12, 0xa, 0xd, 0x115, 
    0x11d, 0xc, 0xb, 0x2, 0x2, 0x116, 0x118, 0x7, 0x67, 0x2, 0x2, 0x117, 
    0x116, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11e, 0x7, 0x62, 0x2, 0x2, 0x11a, 
    0x11e, 0x7, 0x4f, 0x2, 0x2, 0x11b, 0x11e, 0x7, 0x64, 0x2, 0x2, 0x11c, 
    0x11e, 0x7, 0x76, 0x2, 0x2, 0x11d, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x151, 0x5, 0x12, 0xa, 0xc, 0x120, 0x121, 0xc, 0x9, 0x2, 0x2, 0x121, 
    0x122, 0x7, 0x22, 0x2, 0x2, 0x122, 0x151, 0x5, 0x12, 0xa, 0xa, 0x123, 
    0x124, 0xc, 0x8, 0x2, 0x2, 0x124, 0x125, 0x7, 0x6d, 0x2, 0x2, 0x125, 
    0x151, 0x5, 0x12, 0xa, 0x9, 0x126, 0x128, 0xc, 0x4, 0x2, 0x2, 0x127, 
    0x129, 0x7, 0x67, 0x2, 0x2, 0x128, 0x127, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 
    0x12b, 0x7, 0x29, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x12, 0xa, 0x2, 0x12c, 
    0x12d, 0x7, 0x22, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x12, 0xa, 0x5, 0x12e, 
    0x151, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x131, 0xc, 0xa, 0x2, 0x2, 0x130, 
    0x132, 0x7, 0x67, 0x2, 0x2, 0x131, 0x130, 0x3, 0x2, 0x2, 0x2, 0x131, 
    0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x147, 0x7, 0x55, 0x2, 0x2, 0x134, 0x13e, 0x7, 0x6, 0x2, 0x2, 0x135, 
    0x13f, 0x5, 0xc, 0x7, 0x2, 0x136, 0x13b, 0x5, 0x12, 0xa, 0x2, 0x137, 
    0x138, 0x7, 0x8, 0x2, 0x2, 0x138, 0x13a, 0x5, 0x12, 0xa, 0x2, 0x139, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 
    0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x135, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x148, 0x7, 0x7, 0x2, 0x2, 0x141, 0x142, 0x5, 0x32, 0x1a, 0x2, 0x142, 
    0x143, 0x7, 0x5, 0x2, 0x2, 0x143, 0x145, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x148, 0x5, 0x34, 0x1b, 0x2, 0x147, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x147, 0x144, 0x3, 0x2, 0x2, 0x2, 0x148, 
    0x151, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14e, 0xc, 0x5, 0x2, 0x2, 0x14a, 
    0x14f, 0x7, 0x5f, 0x2, 0x2, 0x14b, 0x14f, 0x7, 0x68, 0x2, 0x2, 0x14c, 
    0x14d, 0x7, 0x67, 0x2, 0x2, 0x14d, 0x14f, 0x7, 0x69, 0x2, 0x2, 0x14e, 
    0x14a, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14e, 
    0x14c, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x151, 0x3, 0x2, 0x2, 0x2, 0x150, 
    0xfa, 0x3, 0x2, 0x2, 0x2, 0x150, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x150, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x103, 0x3, 0x2, 0x2, 0x2, 0x150, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x109, 0x3, 0x2, 0x2, 0x2, 0x150, 0x115, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x120, 0x3, 0x2, 0x2, 0x2, 0x150, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x126, 0x3, 0x2, 0x2, 0x2, 0x150, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x149, 0x3, 0x2, 0x2, 0x2, 0x151, 0x154, 
    0x3, 0x2, 0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x13, 0x3, 0x2, 0x2, 0x2, 0x154, 0x152, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x157, 0x5, 0x12, 0xa, 0x2, 0x156, 0x158, 0x9, 
    0x7, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x3, 
    0x2, 0x2, 0x2, 0x158, 0x15, 0x3, 0x2, 0x2, 0x2, 0x159, 0x167, 0x7, 0xa, 
    0x2, 0x2, 0x15a, 0x15b, 0x5, 0x34, 0x1b, 0x2, 0x15b, 0x15c, 0x7, 0x5, 
    0x2, 0x2, 0x15c, 0x15d, 0x7, 0xa, 0x2, 0x2, 0x15d, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x163, 0x5, 0x12, 0xa, 0x2, 0x15f, 0x161, 0x7, 0x23, 
    0x2, 0x2, 0x160, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 0x2, 0x162, 0x164, 0x5, 0x2a, 
    0x16, 0x2, 0x163, 0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x167, 0x7, 0x64, 
    0x2, 0x2, 0x166, 0x159, 0x3, 0x2, 0x2, 0x2, 0x166, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x166, 0x165, 0x3, 0x2, 
    0x2, 0x2, 0x167, 0x17, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x5, 0x32, 
    0x1a, 0x2, 0x169, 0x16a, 0x7, 0x5, 0x2, 0x2, 0x16a, 0x16c, 0x3, 0x2, 
    0x2, 0x2, 0x16b, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 
    0x2, 0x2, 0x16c, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x172, 0x5, 0x34, 
    0x1b, 0x2, 0x16e, 0x170, 0x7, 0x23, 0x2, 0x2, 0x16f, 0x16e, 0x3, 0x2, 
    0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 
    0x2, 0x2, 0x171, 0x173, 0x5, 0x38, 0x1d, 0x2, 0x172, 0x16f, 0x3, 0x2, 
    0x2, 0x2, 0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x174, 0x17e, 0x7, 0x6, 0x2, 0x2, 0x175, 0x17a, 0x5, 0x18, 
    0xd, 0x2, 0x176, 0x177, 0x7, 0x8, 0x2, 0x2, 0x177, 0x179, 0x5, 0x18, 
    0xd, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17c, 0x3, 0x2, 
    0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x17f, 0x5, 0x1a, 0xe, 0x2, 0x17e, 0x175, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x180, 0x185, 0x7, 0x7, 0x2, 0x2, 0x181, 0x183, 0x7, 0x23, 
    0x2, 0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 0x2, 0x2, 0x184, 0x186, 0x5, 0x38, 
    0x1d, 0x2, 0x185, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x3, 0x2, 
    0x2, 0x2, 0x186, 0x191, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x7, 0x6, 
    0x2, 0x2, 0x188, 0x189, 0x5, 0xc, 0x7, 0x2, 0x189, 0x18e, 0x7, 0x7, 
    0x2, 0x2, 0x18a, 0x18c, 0x7, 0x23, 0x2, 0x2, 0x18b, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x18d, 0x18f, 0x5, 0x38, 0x1d, 0x2, 0x18e, 0x18b, 0x3, 0x2, 
    0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x190, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x190, 0x174, 0x3, 0x2, 
    0x2, 0x2, 0x190, 0x187, 0x3, 0x2, 0x2, 0x2, 0x191, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x192, 0x199, 0x5, 0x18, 0xd, 0x2, 0x193, 0x194, 0x5, 0x1c, 0xf, 
    0x2, 0x194, 0x195, 0x5, 0x18, 0xd, 0x2, 0x195, 0x196, 0x5, 0x1e, 0x10, 
    0x2, 0x196, 0x198, 0x3, 0x2, 0x2, 0x2, 0x197, 0x193, 0x3, 0x2, 0x2, 
    0x2, 0x198, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 
    0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x1a9, 0x7, 0x8, 0x2, 0x2, 
    0x19d, 0x19f, 0x7, 0x65, 0x2, 0x2, 0x19e, 0x19d, 0x3, 0x2, 0x2, 0x2, 
    0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x1a0, 0x1a2, 0x7, 0x61, 0x2, 0x2, 0x1a1, 0x1a3, 0x7, 0x6f, 0x2, 0x2, 
    0x1a2, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 
    0x1a3, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a6, 0x7, 0x59, 0x2, 0x2, 
    0x1a5, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 
    0x1a5, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 
    0x1a7, 0x1a9, 0x7, 0x60, 0x2, 0x2, 0x1a8, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x1a8, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
    0x1ab, 0x7, 0x6c, 0x2, 0x2, 0x1ab, 0x1b9, 0x5, 0x12, 0xa, 0x2, 0x1ac, 
    0x1ad, 0x7, 0x8c, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x6, 0x2, 0x2, 0x1ae, 
    0x1b3, 0x5, 0x36, 0x1c, 0x2, 0x1af, 0x1b0, 0x7, 0x8, 0x2, 0x2, 0x1b0, 
    0x1b2, 0x5, 0x36, 0x1c, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 
    0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
    0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
    0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x7, 0x7, 0x2, 0x2, 0x1b7, 
    0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
    0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b9, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bc, 0x7, 0x80, 0x2, 0x2, 0x1bb, 
    0x1bd, 0x9, 0x8, 0x2, 0x2, 0x1bc, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bc, 
    0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1be, 
    0x1c3, 0x5, 0x16, 0xc, 0x2, 0x1bf, 0x1c0, 0x7, 0x8, 0x2, 0x2, 0x1c0, 
    0x1c2, 0x5, 0x16, 0xc, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c2, 
    0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
    0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1d0, 0x7, 0x4d, 0x2, 0x2, 0x1c7, 
    0x1cc, 0x5, 0x18, 0xd, 0x2, 0x1c8, 0x1c9, 0x7, 0x8, 0x2, 0x2, 0x1c9, 
    0x1cb, 0x5, 0x18, 0xd, 0x2, 0x1ca, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
    0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cc, 
    0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
    0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d1, 0x5, 0x1a, 0xe, 0x2, 0x1d0, 
    0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
    0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1d2, 
    0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
    0x1d5, 0x7, 0x92, 0x2, 0x2, 0x1d5, 0x1d7, 0x5, 0x12, 0xa, 0x2, 0x1d6, 
    0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
    0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x7, 0x50, 0x2, 0x2, 0x1d9, 
    0x1da, 0x7, 0x2a, 0x2, 0x2, 0x1da, 0x1df, 0x5, 0x12, 0xa, 0x2, 0x1db, 
    0x1dc, 0x7, 0x8, 0x2, 0x2, 0x1dc, 0x1de, 0x5, 0x12, 0xa, 0x2, 0x1dd, 
    0x1db, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1df, 
    0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
    0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1e3, 0x7, 0x51, 0x2, 0x2, 0x1e3, 0x1e5, 0x5, 0x12, 0xa, 0x2, 0x1e4, 
    0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
    0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
    0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 
    0x7, 0x89, 0x2, 0x2, 0x1e9, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ec, 
    0x9, 0x4, 0x2, 0x2, 0x1eb, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 
    0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 
    0x7, 0x97, 0x2, 0x2, 0x1ee, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 
    0x9, 0x9, 0x2, 0x2, 0x1f0, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f2, 0x9, 
    0xa, 0x2, 0x2, 0x1f2, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x9, 0xb, 
    0x2, 0x2, 0x1f4, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x9, 0xc, 0x2, 
    0x2, 0x1f6, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x5, 0x3a, 0x1e, 
    0x2, 0x1f8, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x7, 0x95, 0x2, 
    0x2, 0x1fa, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x9, 0xb, 0x2, 0x2, 
    0x1fc, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x9, 0xb, 0x2, 0x2, 0x1fe, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x9, 0xb, 0x2, 0x2, 0x200, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x201, 0x202, 0x9, 0xb, 0x2, 0x2, 0x202, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x203, 0x20b, 0x7, 0x95, 0x2, 0x2, 0x204, 0x20b, 0x5, 
    0x2c, 0x17, 0x2, 0x205, 0x20b, 0x7, 0x99, 0x2, 0x2, 0x206, 0x207, 0x7, 
    0x6, 0x2, 0x2, 0x207, 0x208, 0x5, 0x3a, 0x1e, 0x2, 0x208, 0x209, 0x7, 
    0x7, 0x2, 0x2, 0x209, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x203, 0x3, 
    0x2, 0x2, 0x2, 0x20a, 0x204, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x205, 0x3, 
    0x2, 0x2, 0x2, 0x20a, 0x206, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x3e, 0x40, 0x49, 0x4d, 0x53, 0x5a, 0x5d, 0x67, 0x6a, 
    0x70, 0x72, 0x7a, 0x84, 0x87, 0x8d, 0x8f, 0x99, 0xa4, 0xab, 0xae, 0xb3, 
    0xbf, 0xc6, 0xcd, 0xd1, 0xd8, 0xdd, 0xef, 0xf2, 0xf8, 0x110, 0x112, 
    0x117, 0x11d, 0x128, 0x131, 0x13b, 0x13e, 0x144, 0x147, 0x14e, 0x150, 
    0x152, 0x157, 0x160, 0x163, 0x166, 0x16b, 0x16f, 0x172, 0x17a, 0x17e, 
    0x182, 0x185, 0x18b, 0x18e, 0x190, 0x199, 0x19e, 0x1a2, 0x1a5, 0x1a8, 
    0x1b3, 0x1b8, 0x1bc, 0x1c3, 0x1cc, 0x1d0, 0x1d2, 0x1d6, 0x1df, 0x1e4, 
    0x1e6, 0x1eb, 0x20a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SQLiteParser::Initializer SQLiteParser::_init;
