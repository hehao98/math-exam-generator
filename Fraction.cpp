//
// Created by hehao on 18-1-20.
//

#include "Fraction.h"

#include <algorithm>
#include <cassert>

const static int BUF_SIZE =  1024;

static int gcd(int a, int b)
{
    if (a <= b) std::swap(a, b);
    int tmp = a % b;
    while (tmp)
    {
        a = b;
        b = tmp;
        tmp = a % b;
    }
    return b;
}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom)
{
    assert(denominator != 0);
    simplify();
}

void Fraction::simplify()
{
    if (numerator == 0)
    {
        denominator = 1;
        return;
    }

    if ((numerator < 0 && denominator < 0)
            || (numerator > 0 && denominator < 0))
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    int tmp;
    while ((tmp = gcd(numerator, denominator)) != 1)
    {
        numerator   /= tmp;
        denominator /= tmp;
    }
}

Fraction Fraction::operator+(const Fraction &f) const
{
    Fraction result;
    result.numerator   = numerator * f.denominator + f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator+(int v) const
{
    return *this + Fraction(v, 1);
}

Fraction operator+(int v, const Fraction &f)
{
    return f + Fraction(v, 1);
}

Fraction Fraction::operator-(const Fraction &f) const
{
    Fraction result;
    result.numerator   = numerator * f.denominator - f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator-(int v) const
{
    return *this - Fraction(v, 1);
}

Fraction operator-(int v, const Fraction &f)
{
    return Fraction(v, 1) - f;
}

Fraction Fraction::operator*(const Fraction &f) const
{
    Fraction result;
    result.numerator   = numerator * f.numerator;
    result.denominator = denominator * f.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator*(int v) const
{
    return *this * Fraction(v, 1);
}

Fraction operator*(int v, const Fraction &f)
{
    return Fraction(v, 1) * f;
}

Fraction Fraction::operator/(const Fraction &f) const
{
    assert(f.numerator != 0);
    return *this * Fraction(f.denominator, f.numerator);
}

Fraction Fraction::operator/(int v) const
{
    return *this / Fraction(v, 1);
}

Fraction operator/(int v, const Fraction &f)
{
    return Fraction(v, 1) / f;
}

std::string Fraction::toString() const
{
    char buf[BUF_SIZE];
    if (denominator != 1)
    {
        sprintf(buf, "%d/%d", numerator, denominator);
    }
    else
    {
        sprintf(buf, "%d", numerator);
    }
    return std::string(buf);
}

bool Fraction::operator==(const Fraction &rhs) const
{
    return numerator == rhs.numerator &&
           denominator == rhs.denominator;
}

bool Fraction::operator!=(const Fraction &rhs) const
{
    return !(rhs == *this);
}

