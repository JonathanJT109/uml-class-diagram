#include "lexer.hpp"
#include <cctype>
#include <iomanip>
#include <sstream>

void Lexer::printText() { std::cout << text; }

Lexer::Lexer(std::string text) {
  this->text = text;
  position = 0;
  index = 0;
  makeLines();
}

char Lexer::currentChar() {
  if (position > text.size())
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
  while (is_whitespace())
    nextChar();

  if (isalpha(currentChar()))
    return read_word();
  else if (isdigit(currentChar()))
    return read_number();

  switch (currentChar()) {
  case '\0':
    return _default(Kind::EndOfFile);
  case '(':
    return _default(Kind::LeftParenToken);
  case ')':
    return _default(Kind::RightParenToken);
  case '{':
    return _default(Kind::LeftBraceToken);
  case '}':
    return _default(Kind::RightBraceToken);
  case '[':
    return _default(Kind::LeftBracketToken);
  case ']':
    return _default(Kind::RightBracketToken);
  case '+':
    return _default(Kind::PlusToken);
  case '-':
    return _default(Kind::MinusToken);
  case '*':
    return _default(Kind::AsteriskToken);
  case '/':
    if (is_comment())
      return read_comment();
    return _default(Kind::SlashToken);
  case '=':
    return _default(Kind::EqualToken);
  case '\n':
    return _default(Kind::EndOfLineToken);
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

  if (currentChar() == '.' && isdigit(text[position + 1])) {
    nextChar();
    while (isdigit(currentChar()))
      nextChar();
    return Token(Kind::FloatToken, text.substr(start, position - start),
                 {start, index, line});
  }

  pos.end = this->index;
  pos.line = this->line;

  return Token(Kind::IntegerToken, text.substr(start, position - start), pos);
}

bool Lexer::is_comment() {
  if (currentChar() == '/' && text[position + 1] == '/')
    return true;
  return false;
}

Token Lexer::read_comment() {
  Position pos;
  size_t start = this->position;
  pos.start = this->index;

  while (currentChar() != '\n' && currentChar() != '\0')
    nextChar();

  pos.end = this->index;
  pos.line = this->line;

  return Token(Kind::CommentToken, text.substr(start, position - start), pos);
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
    return Token(kind, "\\n", pos);
  }
  index++;
  return Token(kind, text.substr(position++, 1), pos);
}

void Lexer::makeLines() {
  std::istringstream iss(this->text);
  std::string line;
  while (std::getline(iss, line, '\n')) {
    this->lines.push_back(line);
  }
}

std::ostream &operator<<(std::ostream &os, const Kind &kind) {
  static const char *const names[]{
      "EndOfFile",        "UnexpectedToken", "IllegalToken",
      "EndOfLineToken",   "CommentToken",    "IdentifierToken",
      "IntegerToken",     "FloatToken",      "PlusToken",
      "MinusToken",       "AsteriskToken",   "SlashToken",
      "EqualToken",       "LeftParenToken",  "RightParenToken",
      "LeftBraceToken",   "RightBraceToken", "LeftBracketToken",
      "RightBracketToken"};

  return os << names[static_cast<size_t>(kind)];
}

void Lexer::print() {
  for (size_t i = 0; i < lines.size(); ++i) {
    std::cout << lines[i] << std::endl;
    Token token;
    for (token = nextToken();
         this->line <= i && token.getKind() != Kind::EndOfFile;
         token = nextToken()) {
      std::cout << std::string(token.getPos().start, ' ')
                << std::string(token.getPos().end - token.getPos().start, '^')
                << " (" << token.getKind() << ", \"" << token.getValue()
                << "\", " << token.getPos().start << " -> "
                << token.getPos().end << ", line: " << token.getPos().line
                << ")\n";
    }

    if (token.getKind() == Kind::EndOfLineToken) {
      std::cout << std::string(token.getPos().start, ' ') << " ("
                << token.getKind() << ", \"" << token.getValue() << "\", "
                << token.getPos().start << " -> " << token.getPos().end
                << ", line: " << token.getPos().line << ")\n";
    }
  }
  std::cout << "<End of File>" << std::endl;
}

std::string Lexer::result() {
  std::ostringstream output;
  for (size_t i = 0; i < lines.size(); ++i) {
    output << lines[i] << '\n';
    Token token;
    for (token = nextToken();
         this->line <= i && token.getKind() != Kind::EndOfFile;
         token = nextToken()) {
      output << std::string(token.getPos().start, ' ')
             << std::string(token.getPos().end - token.getPos().start, '^')
             << " (" << token.getKind() << ", \"" << token.getValue() << "\", "
             << token.getPos().start << " -> " << token.getPos().end
             << ", line: " << token.getPos().line << ")\n";
    }

    if (token.getKind() == Kind::EndOfLineToken) {
      output << std::string(token.getPos().start, ' ') << " ("
             << token.getKind() << ", \"" << token.getValue() << "\", "
             << token.getPos().start << " -> " << token.getPos().end
             << ", line: " << token.getPos().line << ")\n";
    }
  }

  output << "<End of File>\n";

  return output.str();
}
