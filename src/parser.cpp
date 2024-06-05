// parser.cpp
#include "parser.hpp"
#include <stdexcept>
#include <iostream>


Parser::Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.nextToken()) {
    // Constructor initializes currentToken directly

}


void Parser::eat(TokenType type) {
    if (currentToken.type == type) {
        currentToken = lexer.nextToken();
    } else {
        throw std::runtime_error("Parser error: Unexpected token type.");
    }
}

std::unique_ptr<ASTNode> Parser::factor() {
    if (currentToken.type == TokenType::NUMBER) {
        int value = std::stoi(currentToken.value);
        eat(TokenType::NUMBER);
        return std::make_unique<IntegerLiteral>(value);
    }
    throw std::runtime_error("Parser error: Invalid syntax in factor.");
}

std::unique_ptr<ASTNode> Parser::term() {
    auto node = factor();
    while (currentToken.type == TokenType::ASTERISK || currentToken.type == TokenType::SLASH) {
        char op = currentToken.value[0];
        std::cout << "Operator in term(): " << op << std::endl;  // Debugging print
        eat(currentToken.type);
        node = std::make_unique<BinaryOp>(std::move(node), op, factor());
    }
    return node;
}

std::unique_ptr<ASTNode> Parser::expr() {
    auto node = term();
    while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS) {
        char op = currentToken.value[0];
        eat(currentToken.type);
        node = std::make_unique<BinaryOp>(std::move(node), op, term());
    }
    return node;
}


std::unique_ptr<ASTNode> Parser::parse() {
    return expr();  // Start with the highest precedence
}
