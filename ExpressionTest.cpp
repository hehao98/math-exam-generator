//
// Created by hehao on 18-1-20.
//

#include <string>
#include <iostream>
#include <gtest/gtest.h>

#include "Expression.h"

TEST(ExpressionTest, AdditionExpressionTest)
{
    auto *v1 = new ValueExpression(Fraction(3, 4));
    auto *v2 = new ValueExpression(Fraction(4, 7));

    auto *exp1 = new AdditionExpression(v1, v2);
    ASSERT_TRUE(exp1->evaluate().toString() == "37/28");

    auto *exp2 = new AdditionExpression(exp1, v2);
    ASSERT_TRUE(exp2->evaluate().toString() == "53/28");
}

TEST(ExpressionTest, GenerationTest)
{
    std::cout << "generateExpression(2, 5, -10, 10, "
            "ALLOW_ADD|ALLOW_SUB|ALLOW_DIV|ALLOW_FRACTION)" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Expression " << i << ": ";
        Expression *exp = generateExpression(2, 5, -10, 10,
                              ALLOW_ADD|ALLOW_SUB|ALLOW_MULTI|ALLOW_DIV|ALLOW_FRACTION);
        std::cout << exp->toString() << "="
                  << exp->evaluate().toString() << std::endl;
        delete exp;
    }
}