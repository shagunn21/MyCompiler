#ifndef AST_HPP
#define AST_HPP

#include <memory>
#include <string>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual std::string to_string() const = 0;
};

class BinaryOp : public ASTNode {
public:
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
    char op;  // Operator

    BinaryOp(std::unique_ptr<ASTNode> left, char op, std::unique_ptr<ASTNode> right)
        : left(std::move(left)), right(std::move(right)), op(op) {}

    virtual std::string to_string() const override {
        return "(" + left->to_string() + " " + op + " " + right->to_string() + ")";
    }
};

class IntegerLiteral : public ASTNode {
public:
    int value;

    IntegerLiteral(int value) : value(value) {}

    virtual std::string to_string() const override {
        return std::to_string(value);
    }
};

#endif // AST_HPP
