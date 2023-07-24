// Libraries
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// TODO: Expand Kind Enum to include more
// TODO: Print tokens per line
// TODO: Break program down into more files

enum Kind {
  NumberToken,
  PlusToken,
  MinusToken,
  AsteriskToken,
  SlashToken,
  LParenToken,
  RParenToken,
  VariableTypeToken,
  EndOfLineToken,
  IllegalToken,
  UnexpectedToken,
  EqualToken,
  IdentifierToken,
  EndOfFile,
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
  Kind getKind();
  std::string getValue();
  Position getPos();
};

Token::Token(Kind kind, std::string text, Position pos) {
  this->kind = kind;
  this->value = text;
  this->pos = pos;
}

Kind Token::Token::getKind() { return this->kind; }

std::string Token::getValue() { return this->value; }

Position Token::getPos() { return this->pos; }

class Lexer {
private:
  std::string text;
  size_t position;
  size_t line;
  size_t index;
  bool is_newline();
  bool is_whitespace();
  char currentChar();
  void nextChar();

public:
  Lexer(std::string text);
  void printText();
  Token nextToken();
  Token read_word();
  Token read_number();
  Token _default(Kind);
};

void Lexer::printText() { std::cout << text; }

Lexer::Lexer(std::string text) { this->text = text; }

char Lexer::currentChar() {
  if (position >= text.size())
    return '\0';

  return text[position];
}

void Lexer::nextChar() {
  position++;
  index++;
}

bool Lexer::is_whitespace() {
  if (text[position] == ' ')
    return true;
  return false;
}

bool Lexer::is_newline() {
  if (text[position] == '\n')
    return true;
  return false;
}

Token Lexer::nextToken() {
  if (position >= text.size()) {
    Position pos;
    pos.end = this->position;
    pos.start = this->position;
    pos.line = this->line;
    return Token(Kind::EndOfFile, "", pos);
  }

  while (is_whitespace())
    nextChar();

  if (isalpha(currentChar()))
    return read_word();
  else if (isdigit(currentChar()))
    return read_number();

  switch (currentChar()) {
  case '(':
    return _default(Kind::LParenToken);
  case ')':
    return _default(Kind::RParenToken);
  case '+':
    return _default(Kind::PlusToken);
  case '-':
    return _default(Kind::MinusToken);
  case '*':
    return _default(Kind::AsteriskToken);
  case '/':
    return _default(Kind::SlashToken);
  case '\n':
    return _default(Kind::EndOfLineToken);
  case '=':
    return _default(Kind::EqualToken);
  default:
    return _default(Kind::UnexpectedToken);
  }
}

Token Lexer::read_word() {
  Position pos;
  size_t start = this->position;

  pos.start = this->index;

  while (isalpha(currentChar()))
    nextChar();

  pos.end = this->index;
  pos.line = this->line;

  return Token(Kind::IdentifierToken, text.substr(start, position - start),
               pos);
}

Token Lexer::read_number() {
  Position pos;
  size_t start = this->position;

  pos.start = this->index;

  while (isdigit(currentChar()))
    nextChar();

  pos.end = this->index;
  pos.line = this->line;

  return Token(Kind::NumberToken, text.substr(start, position - start), pos);
}

Token Lexer::_default(Kind kind) {
  Position pos;
  pos.start = this->index;
  pos.end = this->index + 1;
  pos.line = this->line;
  if (is_newline()) {
    position++;
    index = 0;
    line++;
    return Token(kind, "", pos);
  }
  index++;
  return Token(kind, text.substr(position++, 1), pos);
}

std::ostream &operator<<(std::ostream &os, const Kind &kind) {
  static const char *const names[]{
      "Number",     "Plus",       "Minus",        "Asterisk",  "Slash",
      "LeftParen",  "RightParen", "VariableType", "EndOfLine", "Illegal",
      "Unexpected", "Equal",      "Identifier",   "EndOfFile"};

  return os << names[static_cast<size_t>(kind)];
}

int main(int argc, char const *argv[]) {
  std::ifstream file(argv[1]);
  if (!file) {
    std::cout << "File not found" << std::endl;
    return 1;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  std::string text = buffer.str();

  Lexer test(text);

  test.printText();
  while (true) {
    auto token = test.nextToken();
    if (token.getKind() == Kind::EndOfFile) {
      std::cout << "<End of File>\n";
      break;
    } else if (token.getKind() == Kind::EndOfLineToken)
      continue;
    std::cout << std::string(token.getPos().start, ' ')
              << std::string(token.getPos().end - token.getPos().start, '^')
              << " (" << token.getKind() << ", \"" << token.getValue() << "\", "
              << token.getPos().start << " -> " << token.getPos().end
              << ", line: " << token.getPos().line << ")\n";
  }

  return 0;
}
