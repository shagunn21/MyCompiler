#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"
#include "ast.hpp"
#include <memory>

class Parser {
    Lexer& lexer;  // Change to reference
    Token currentToken;

    void eat(TokenType type);
    std::unique_ptr<ASTNode> factor();
    std::unique_ptr<ASTNode> term();
    std::unique_ptr<ASTNode> expr();

public:
    explicit Parser(Lexer& lexer);  // Changed to reference
    std::unique_ptr<ASTNode> parse();
};

#endif // PARSER_HPP
