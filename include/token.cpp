#include "token.hpp"

Token::Token() {
  this->kind = Kind::UnexpectedToken;
  this->value = "";
  this->pos = {0, 0, 0};
}

Token::Token(Kind kind, std::string text, Position pos) {
  this->kind = kind;
  this->value = text;
  this->pos = pos;
}

Kind Token::Token::getKind() { return this->kind; }

std::string Token::getValue() { return this->value; }

Position Token::getPos() { return this->pos; }
