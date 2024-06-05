// lexer.cpp
#include "lexer.hpp"
#include <cctype>  // for std::isdigit, std::isalpha, etc.
#include <stdexcept> 

Lexer::Lexer(const std::string& source) : source(source), pos(0), currentChar(source.empty() ? '\0' : source[0]) {}

void Lexer::advance() {
    pos++;
    if (pos < source.length()) {
        currentChar = source[pos];
    } else {
        currentChar = '\0';  // End of source
    }
}

void Lexer::readChar() {
    if (pos < source.length()) {
        currentChar = source[pos];
    } else {
        currentChar = '\0';  // End of source
    }
}

void Lexer::skipWhitespace() {
    while (currentChar != '\0' && std::isspace(currentChar)) {
        advance();
    }
}

Token Lexer::number() {
    std::string result;
    while (currentChar != '\0' && std::isdigit(currentChar)) {
        result += currentChar;
        advance();
    }
    return Token(TokenType::NUMBER, result);
}

Token Lexer::identifier() {
    std::string result;
    while (currentChar != '\0' && std::isalnum(currentChar)) {
        result += currentChar;
        advance();
    }
    // Check if the identifier is a reserved keyword
    if (result == "int") return Token(TokenType::INT, result);
    if (result == "return") return Token(TokenType::RETURN, result);
    if (result == "if") return Token(TokenType::IF, result);
    if (result == "else") return Token(TokenType::ELSE, result);
    return Token(TokenType::IDENTIFIER, result);
}

Token Lexer::createToken(TokenType type) {
    std::string value(1, currentChar);
    advance();  // Move past the token's character
    return Token(type, value);
}

Token Lexer::nextToken() {
    while (currentChar != '\0') {
        if (std::isspace(currentChar)) {
            skipWhitespace();
            continue;
        }

        if (std::isdigit(currentChar)) {
            return number();
        }

        if (std::isalpha(currentChar)) {
            return identifier();
        }

        switch (currentChar) {
            case '+': return createToken(TokenType::PLUS);
            case '-': return createToken(TokenType::MINUS);
            case '*': return createToken(TokenType::ASTERISK);
            case '/': return createToken(TokenType::SLASH);
            case '(': return createToken(TokenType::LPAREN);
            case ')': return createToken(TokenType::RPAREN);
            case '{': return createToken(TokenType::LBRACE);
            case '}': return createToken(TokenType::RBRACE);
            case ';': return createToken(TokenType::SEMICOLON);
            case '=': return createToken(TokenType::ASSIGN);
            default:
                throw std::runtime_error("Lexer error: Unknown character '" + std::string(1, currentChar) + "'");
        }
    }
    return Token(TokenType::EOF_TOK, "");  // End of file token
}
