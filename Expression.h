//
// Expression class can describe any mathematical expression
// with +-/* operators and int/fraction operands.
//
// Use generateExpression() interface to get a randomly generated Expression\
// Use evaluate() method to get its value, and use toString() method to get its
// string representation.
//
// Created by Hao He on 18-1-19.
//

#ifndef MATH_EXAM_GENERATOR_EXPRESSION_H
#define MATH_EXAM_GENERATOR_EXPRESSION_H

#include <string>
#include "Fraction.h"

enum ValueType
{
    TYPE_INT,
    TYPE_FRACTION,
};

struct Value
{
    ValueType type;
    union
    {
        int      intValue;
        Fraction fractionValue;
    } val;

    Value operator+(const Value &v) const;
    Value operator-(const Value &v) const;
    Value operator*(const Value &v) const;
    Value operator/(const Value &v) const;
    std::string toString() const;
};

class Expression
{
public:
    virtual ~Expression();
    virtual Value evaluate() = 0;
    virtual std::string toString() = 0;
};

class ValueExpression : public Expression
{
public:
    explicit ValueExpression(Value value) : value_(value) {}

    virtual Value evaluate() { return value_; }

    virtual std::string toString();
private:
    Value value_;
};

class AdditionExpression : public Expression
{
public:
    explicit AdditionExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}

    virtual Value evaluate();

    virtual std::string toString();
private:
    Expression *left_;
    Expression *right_;
};

class SubtractionExpression : public Expression
{
public:
    explicit SubtractionExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}

    virtual Value evaluate();

    virtual std::string toString();
private:
    Expression *left_;
    Expression *right_;
};

class MultiplicationExpression : public Expression
{
public:
    explicit MultiplicationExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}

    virtual Value evaluate();

    virtual std::string toString();
private:
    Expression *left_;
    Expression *right_;
};

class DivisionExpression : public Expression
{
public:
    explicit DivisionExpression(Expression *left, Expression *right)
            : left_(left), right_(right) {}

    virtual Value evaluate();

    virtual std::string toString();
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
//                     Caller MUST manually free the memory.
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
