// token.cpp
#include "token.hpp"
#include <sstream>

Token::Token(TokenType type, std::string value)
    : type(type), value(std::move(value)) {}

std::string Token::toString() const {
    std::stringstream ss;
    ss << "Token(";
    switch (type) {
        case TokenType::INT: ss << "INT"; break;
        case TokenType::RETURN: ss << "RETURN"; break;
        case TokenType::IF: ss << "IF"; break;
        case TokenType::ELSE: ss << "ELSE"; break;
        case TokenType::IDENTIFIER: ss << "IDENTIFIER"; break;
        case TokenType::NUMBER: ss << "NUMBER"; break;
        case TokenType::PLUS: ss << "PLUS"; break;
        case TokenType::MINUS: ss << "MINUS"; break;
        case TokenType::ASTERISK: ss << "ASTERISK"; break;
        case TokenType::SLASH: ss << "SLASH"; break;
        case TokenType::LPAREN: ss << "LPAREN"; break;
        case TokenType::RPAREN: ss << "RPAREN"; break;
        case TokenType::LBRACE: ss << "LBRACE"; break;
        case TokenType::RBRACE: ss << "RBRACE"; break;
        case TokenType::SEMICOLON: ss << "SEMICOLON"; break;
        case TokenType::ASSIGN: ss << "ASSIGN"; break;
        case TokenType::EOF_TOK: ss << "EOF_TOK"; break;
        default: ss << "UNKNOWN";
    }
    ss << ", \"" << value << "\")";
    return ss.str();
}
