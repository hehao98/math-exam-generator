//
// Expression class can describe any mathematical expression
// with +-/* operators and int/fraction operands.
//
// Use generateExpression() function to get a randomly generated Expression,
// Use evaluate() method to get its value, and use toString() method to get its
// string representation.
//
// Created by Hao He on 18-1-19.
//

#ifndef MATH_EXAM_GENERATOR_EXPRESSION_H
#define MATH_EXAM_GENERATOR_EXPRESSION_H

#include <string>
#include "Fraction.h"


class Expression
{
public:
    virtual ~Expression() = default;
    virtual Fraction evaluate() = 0;
    virtual int priority() const = 0;
    virtual std::string toString() const = 0;
};

class ValueExpression : public Expression
{
public:
    explicit ValueExpression(Fraction value) : value_(value) {}

    Fraction evaluate() override { return value_; }

    int priority() const override { return 3; }

    std::string toString() const override;
private:
    Fraction value_;
};

class AdditionExpression : public Expression
{
public:
    explicit AdditionExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}
    ~AdditionExpression() override;

    Fraction evaluate() override;

    int priority() const override { return 1; }

    std::string toString() const override;
private:
    Expression *left_;
    Expression *right_;
};

class SubtractionExpression : public Expression
{
public:
    explicit SubtractionExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}
    ~SubtractionExpression() override;

    Fraction evaluate() override;

    int priority() const override { return 1; }

    std::string toString() const override;
private:
    Expression *left_;
    Expression *right_;
};

class MultiplicationExpression : public Expression
{
public:
    explicit MultiplicationExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}
    ~MultiplicationExpression() override;

    Fraction evaluate() override;

    int priority() const override { return 2; }

    std::string toString() const override;
private:
    Expression *left_;
    Expression *right_;
};

class DivisionExpression : public Expression
{
public:
    explicit DivisionExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}
    ~DivisionExpression() override;

    Fraction evaluate() override;

    int priority() const override { return 2; }

    std::string toString() const override;
private:
    Expression *left_;
    Expression *right_;
};

const int ALLOW_ADD      = 0x1;
const int ALLOW_SUB      = 0x2;
const int ALLOW_MULTI    = 0x4;
const int ALLOW_DIV      = 0x8;
const int ALLOW_FRACTION = 0x10;

//
// generateExpression: Randomly generate expression with parameters given,
//                     Caller MUST manually free the memory using delete.
// Parameters: minOps   - minimum number of operands in the expression.
//             maxOps   - maximum number of operands in the expression.
//             minValue - minimum operator value in the expression.
//             maxValue - maximum operator value in the expression.
//             flags    - A variety of options. See the constants above.
// Returns: Pointer to the expression.
//
Expression *generateExpression(int minOps, int maxOps,
                               int minValue, int maxValue, int flags);


#endif //MATH_EXAM_GENERATOR_EXPRESSION_H
