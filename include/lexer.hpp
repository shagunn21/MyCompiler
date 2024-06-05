// lexer.hpp
#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <string>
#include <cstddef>  // for size_t

class Lexer {
public:
    explicit Lexer(const std::string& source);
    Token nextToken();

private:
    std::string source;
    size_t pos;
    char currentChar;

    void advance();
    void skipWhitespace();
    Token number();
    Token identifier();
    Token createToken(TokenType type);
    void readChar();
};

#endif // LEXER_HPP
