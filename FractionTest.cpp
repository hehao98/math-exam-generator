//
// Created by hehao on 18-1-20.
//

#include <string>
#include <gtest/gtest.h>

#include "Fraction.h"


TEST(FractionTest, DataTest)
{
    Fraction f(1, 3);

    ASSERT_EQ(f.numerator, 1);
    ASSERT_EQ(f.denominator, 3);
}

TEST(FractionTest, AddTest)
{
    Fraction f1 = Fraction(3, 4) + Fraction(2, 3);
    ASSERT_EQ(f1, Fraction(17, 12));

    Fraction f2 = Fraction(2, 3) + Fraction(4, 3);
    ASSERT_EQ(f2, Fraction(2, 1));

    Fraction f3 = Fraction(-2, 3) + Fraction(2, 3);
    ASSERT_EQ(f3, Fraction(0, 1));

    Fraction f4 = Fraction(3, -4) + Fraction(-2, 3);
    ASSERT_EQ(f4, Fraction(-17, 12));

    Fraction f5 = Fraction(2, 3) + 2;
    ASSERT_EQ(f5, Fraction(8, 3));

    Fraction f6 = 3 + Fraction(-2, 3);
    ASSERT_EQ(f6, Fraction(7, 3));
}

TEST(FractionTest, SubTest)
{
    Fraction f1 = Fraction(3, 4) - Fraction(2, 3);
    ASSERT_EQ(f1, Fraction(1, 12));

    Fraction f2 = Fraction(2, 3) - Fraction(4, 3);
    ASSERT_EQ(f2, Fraction(-2, 3));

    Fraction f3 = Fraction(-2, 3) - 0;
    ASSERT_EQ(f3, Fraction(-2, 3));

    Fraction f4 = Fraction(3, -4) + Fraction(-2, 3);
    ASSERT_EQ(f4, Fraction(-17, 12));

    Fraction f5 = Fraction(2, 3) - 2;
    ASSERT_EQ(f5, Fraction(-4, 3));

    Fraction f6 = 3 - Fraction(-2, 3);
    ASSERT_EQ(f6, Fraction(11, 3));
}

TEST(FractionTest, MultiplyTest)
{
    Fraction f1 = Fraction(3, 4) * Fraction(2, 3);
    ASSERT_EQ(f1, Fraction(1, 2));

    Fraction f2 = Fraction(2, 3) * Fraction(-4, 3);
    ASSERT_EQ(f2, Fraction(-8, 9));

    Fraction f3 = Fraction(-2, 3) * 0;
    ASSERT_EQ(f3, Fraction(0, 1));

    Fraction f4 = Fraction(3, -4) * Fraction(-2, 3);
    ASSERT_EQ(f4, Fraction(1, 2));

    Fraction f5 = Fraction(2, 3) * 2;
    ASSERT_EQ(f5, Fraction(4, 3));

    Fraction f6 = 3 * Fraction(-2, 3);
    ASSERT_EQ(f6, Fraction(-2, 1));
}

TEST(FractionTest, DivTest)
{
    Fraction f1 = Fraction(3, 4) / Fraction(2, 3);
    ASSERT_EQ(f1, Fraction(9, 8));

    Fraction f2 = Fraction(-2, 3) / Fraction(4, 3);
    ASSERT_EQ(f2, Fraction(-1, 2));

    Fraction f3 = 0 / Fraction(-2, 3);
    ASSERT_EQ(f3, Fraction(0, 1));

    Fraction f4 = Fraction(3, -4) / Fraction(-2, 3);
    ASSERT_EQ(f4, Fraction(9, 8));

    Fraction f5 = Fraction(2, 3) / 2;
    ASSERT_EQ(f5, Fraction(1, 3));

    Fraction f6 = 3 / Fraction(-2, 3);
    ASSERT_EQ(f6, Fraction(-9, 2));
}

TEST(FractionTest, ToStringTest)
{
    ASSERT_TRUE(Fraction(2, 3).toString() == "2/3");
    ASSERT_TRUE(Fraction(8, 3).toString() == "8/3");
    ASSERT_TRUE(Fraction(6, 3).toString() == "2");
    ASSERT_TRUE(Fraction(0, 3).toString() == "0");
}

