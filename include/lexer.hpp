#ifndef lexer_hpp
#define lexer_hpp

#include "token.hpp"
#include <iostream>
#include <string>
#include <vector>

class Lexer {
private:
  std::string text;
  size_t position;
  size_t line;
  size_t index;
  bool is_newline();
  bool is_whitespace();
  bool is_comment();
  char currentChar();
  void nextChar();
  void makeLines();
  std::vector<std::string> lines;

public:
  Lexer(std::string text);
  void printText();
  Token read_comment();
  Token nextToken();
  Token read_word();
  Token read_number();
  Token _default(Kind);
  void print();
  std::string result();
};

#endif /* lexer_hpp */
