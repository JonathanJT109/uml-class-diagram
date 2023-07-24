#ifndef token_hpp
#define token_hpp

#include <iostream>
#include <string>

enum Kind {
  // Standard
  EndOfFile,
  UnexpectedToken,
  IllegalToken,
  EndOfLineToken,
  CommentToken,

  // Identifiers and literals
  IdentifierToken,
  IntegerToken,
  FloatToken,

  // Operators
  PlusToken,
  MinusToken,
  AsteriskToken,
  SlashToken,
  EqualToken,

  // Comparison

  // Symbols
  LeftParenToken,
  RightParenToken,
  LeftBraceToken,
  RightBraceToken,
  LeftBracketToken,
  RightBracketToken,
};

struct Position {
  size_t start;
  size_t end;
  size_t line;
};

class Token {
private:
  Kind kind;
  std::string value;
  Position pos;

public:
  Token(Kind, std::string, Position);
  Token();
  Kind getKind();
  std::string getValue();
  Position getPos();
};

#endif /*token_hpp*/
