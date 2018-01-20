//
// Created by Hao He on 18-1-19.
//

#include <random>
#include <iostream>

#include "Expression.h"

//Helper constants
const int ADD   = 0;
const int SUB   = 1;
const int MULTI = 2;
const int DIV   = 3;

// Helper Functions
int getRandomNumber(int min, int max);
Expression *constructExpression(Fraction *operands, int *operators,
                                int begin, int end);

std::string ValueExpression::toString() const
{
    if (value_.denominator != 1 || value_.numerator < 0)
    {
        return "(" + value_.toString() + ")";
    }
    return value_.toString();
}

AdditionExpression::~AdditionExpression()
{
    delete left_;
    delete right_;
}

Fraction AdditionExpression::evaluate()
{
    return left_->evaluate() + right_->evaluate();
}

std::string AdditionExpression::toString() const
{
    std::string leftStr, rightStr;

    if (left_->priority() < priority())
    {
        leftStr = "(" + left_->toString() + ")";
    }
    else
    {
        leftStr = left_->toString();
    }

    if (right_->priority() < priority())
    {
        rightStr = "(" + right_->toString() + ")";
    }
    else
    {
        rightStr = right_->toString();
    }

    return leftStr + "+" + rightStr;
}

SubtractionExpression::~SubtractionExpression()
{
    delete left_;
    delete right_;
}

Fraction SubtractionExpression::evaluate()
{
    return left_->evaluate() - right_->evaluate();
}

std::string SubtractionExpression::toString() const
{
    std::string leftStr, rightStr;

    if (left_->priority() < priority())
    {
        leftStr = "(" + left_->toString() + ")";
    }
    else
    {
        leftStr = left_->toString();
    }

    if (right_->priority() < priority())
    {
        rightStr = "(" + right_->toString() + ")";
    }
    else
    {
        rightStr = right_->toString();
    }

    return leftStr + "-" + rightStr;
}

Fraction MultiplicationExpression::evaluate()
{
    return left_->evaluate() * right_->evaluate();
}

std::string MultiplicationExpression::toString() const
{
    std::string leftStr, rightStr;

    if (left_->priority() < priority())
    {
        leftStr = "(" + left_->toString() + ")";
    }
    else
    {
        leftStr = left_->toString();
    }

    if (right_->priority() < priority())
    {
        rightStr = "(" + right_->toString() + ")";
    }
    else
    {
        rightStr = right_->toString();
    }

    return leftStr + "*" + rightStr;
}

MultiplicationExpression::~MultiplicationExpression()
{
    delete left_;
    delete right_;
}

Fraction DivisionExpression::evaluate()
{
    return left_->evaluate() / right_->evaluate();
}

std::string DivisionExpression::toString() const
{
    std::string leftStr, rightStr;

    if (left_->priority() < priority())
    {
        leftStr = "(" + left_->toString() + ")";
    }
    else
    {
        leftStr = left_->toString();
    }

    if (right_->priority() < priority())
    {
        rightStr = "(" + right_->toString() + ")";
    }
    else
    {
        rightStr = right_->toString();
    }

    return leftStr + "/" + rightStr;
}

DivisionExpression::~DivisionExpression()
{
    delete left_;
    delete right_;
}

Expression *generateExpression(int minOps, int maxOps,
                               int minValue, int maxValue, int flags)
{
    int operandCount = getRandomNumber(minOps, maxOps);
    int operatorCount = operandCount - 1;
    auto *operands = new Fraction[operandCount];
    auto *operators = new int[operatorCount];

    for (int i = 0; i < operandCount; ++i)
    {
        int numerator, denominator = 1;
        if (flags & ALLOW_FRACTION)
        {
            denominator = getRandomNumber(minValue, maxValue);
            if (denominator == 0) denominator = 1;
        }
        numerator = getRandomNumber(minValue, maxValue);
        operands[i] = Fraction(numerator, denominator);
    }

    for (int i = 0; i < operatorCount; ++i)
    {
        int buf[16], size = 0;
        if (flags & ALLOW_ADD)
        {
            buf[size++] = ADD;
        }
        if (flags & ALLOW_SUB)
        {
            buf[size++] = SUB;
        }
        if (flags & ALLOW_MULTI)
        {
            buf[size++] = MULTI;
        }
        if (flags & ALLOW_DIV)
        {
            buf[size++] = DIV;
        }
        operators[i] = buf[getRandomNumber(0, size - 1)];
    }

    Expression *result = constructExpression(operands, operators, 0, operandCount);

    delete[] operands;
    delete[] operators;
    return result;
}

Expression *constructExpression(Fraction *operands, int *operators,
                                int begin, int end)
{
    // End recursion
    if (end - begin <= 1)
    {
        return new ValueExpression(operands[begin]);
    }

    int mid = begin + (end - begin) / 2;
    Expression *left = constructExpression(operands, operators, begin, mid);
    Expression *right = constructExpression(operands, operators, mid, end);

    switch (operators[mid - 1])
    {
        case ADD:
            return new AdditionExpression(left, right);
        case SUB:
            return new SubtractionExpression(left, right);
        case MULTI:
            return new MultiplicationExpression(left, right);
        case DIV:
            if (right->evaluate() != Fraction(0, 1)) // Avoid 0
                return new DivisionExpression(left, right);
            else
                return new AdditionExpression(left, right);
        default:
            return nullptr;
    }
}

int getRandomNumber(int min, int max)
{
    static std::default_random_engine e((unsigned)time(nullptr));
    return static_cast<int>(e() % (max-min+1) + min);
}

