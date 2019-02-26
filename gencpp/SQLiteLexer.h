
// Generated from ./SQLite.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SQLiteLexer : public antlr4::Lexer {
public:
  enum {
    UNSUPPORTED_KEYWORDS = 1, SCOL = 2, DOT = 3, OPEN_PAR = 4, CLOSE_PAR = 5, 
    COMMA = 6, ASSIGN = 7, STAR = 8, PLUS = 9, MINUS = 10, TILDE = 11, PIPE2 = 12, 
    DIV = 13, MOD = 14, LT2 = 15, GT2 = 16, AMP = 17, PIPE = 18, LT = 19, 
    LT_EQ = 20, GT = 21, GT_EQ = 22, EQ = 23, NOT_EQ1 = 24, NOT_EQ2 = 25, 
    K_ABORT = 26, K_ADD = 27, K_AFTER = 28, K_ALL = 29, K_ALTER = 30, K_ANALYZE = 31, 
    K_AND = 32, K_AS = 33, K_ASC = 34, K_ATTACH = 35, K_AUTOINCREMENT = 36, 
    K_BEFORE = 37, K_BEGIN = 38, K_BETWEEN = 39, K_BY = 40, K_CASCADE = 41, 
    K_CASE = 42, K_CAST = 43, K_CHECK = 44, K_COLLATE = 45, K_COLUMN = 46, 
    K_COMMIT = 47, K_CONFLICT = 48, K_CONSTRAINT = 49, K_CREATE = 50, K_CROSS = 51, 
    K_CURRENT_DATE = 52, K_CURRENT_TIME = 53, K_CURRENT_TIMESTAMP = 54, 
    K_DATABASE = 55, K_DEFAULT = 56, K_DEFERRABLE = 57, K_DEFERRED = 58, 
    K_DELETE = 59, K_DESC = 60, K_DETACH = 61, K_DISTINCT = 62, K_DROP = 63, 
    K_EACH = 64, K_ELSE = 65, K_END = 66, K_ESCAPE = 67, K_EXCEPT = 68, 
    K_EXCLUSIVE = 69, K_EXISTS = 70, K_EXPLAIN = 71, K_FAIL = 72, K_FOR = 73, 
    K_FOREIGN = 74, K_FROM = 75, K_FULL = 76, K_GLOB = 77, K_GROUP = 78, 
    K_HAVING = 79, K_IF = 80, K_IGNORE = 81, K_IMMEDIATE = 82, K_IN = 83, 
    K_INDEX = 84, K_INDEXED = 85, K_INITIALLY = 86, K_INNER = 87, K_INSERT = 88, 
    K_INSTEAD = 89, K_INTERSECT = 90, K_INTO = 91, K_IS = 92, K_ISNULL = 93, 
    K_JOIN = 94, K_LEFT = 95, K_LIKE = 96, K_LIMIT = 97, K_MATCH = 98, K_NATURAL = 99, 
    K_NO = 100, K_NOT = 101, K_NOTNULL = 102, K_NULL = 103, K_OF = 104, 
    K_OFFSET = 105, K_ON = 106, K_OR = 107, K_ORDER = 108, K_OUTER = 109, 
    K_PLAN = 110, K_PRAGMA = 111, K_PRIMARY = 112, K_RAISE = 113, K_RECURSIVE = 114, 
    K_REFERENCES = 115, K_REGEXP = 116, K_REINDEX = 117, K_RELEASE = 118, 
    K_RENAME = 119, K_REPLACE = 120, K_RESTRICT = 121, K_RIGHT = 122, K_ROLLBACK = 123, 
    K_ROW = 124, K_SAVEPOINT = 125, K_SELECT = 126, K_SET = 127, K_TABLE = 128, 
    K_TEMP = 129, K_TEMPORARY = 130, K_THEN = 131, K_TO = 132, K_TRANSACTION = 133, 
    K_TRIGGER = 134, K_UNION = 135, K_UNIQUE = 136, K_UPDATE = 137, K_USING = 138, 
    K_VACUUM = 139, K_VALUES = 140, K_VIEW = 141, K_VIRTUAL = 142, K_WHEN = 143, 
    K_WHERE = 144, K_WITH = 145, K_WITHOUT = 146, IDENTIFIER = 147, UNQUOTED_IDENTIFIER = 148, 
    NUMERIC_LITERAL = 149, BIND_PARAMETER = 150, STRING_LITERAL = 151, BLOB_LITERAL = 152, 
    SINGLE_LINE_COMMENT = 153, SPACES = 154, UNEXPECTED_CHAR = 155
  };

  SQLiteLexer(antlr4::CharStream *input);
  ~SQLiteLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

