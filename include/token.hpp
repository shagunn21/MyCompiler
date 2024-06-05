// token.hpp
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum class TokenType {
    INT, RETURN, IF, ELSE,
    IDENTIFIER, NUMBER,
    PLUS, MINUS, ASTERISK, SLASH,
    LPAREN, RPAREN, LBRACE, RBRACE,
    SEMICOLON, ASSIGN,
    EOF_TOK  // EOF is a macro in some environments, hence EOF_TOK
};

class Token {
public:
    TokenType type;
    std::string value;

    Token(TokenType type, std::string value);
    std::string toString() const;
};

#endif // TOKEN_HPP
