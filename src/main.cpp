// main.cpp
#include "lexer.hpp"
#include "parser.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    std::string source = "3 + 4 * 8";
    Lexer lexer(source);
    Parser parser(lexer);

    try {
        std::unique_ptr<ASTNode> ast = parser.parse();
        std::cout << "AST: " << ast->to_string() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
