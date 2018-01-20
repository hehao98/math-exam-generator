//
// Created by hehao on 18-1-20.
//

#ifndef MATH_EXAM_GENERATOR_FRACTION_H
#define MATH_EXAM_GENERATOR_FRACTION_H

#include <string>

struct Fraction
{
    int numerator;
    int denominator;

    explicit Fraction(int num = 1, int denom = 1);
    void simplify();

    bool operator==(const Fraction &rhs) const;
    bool operator!=(const Fraction &rhs) const;

    Fraction operator+(const Fraction &f) const;
    Fraction operator+(int v) const;
    friend Fraction operator+(int v, const Fraction &f);

    Fraction operator-(const Fraction &f) const;
    Fraction operator-(int v) const;
    friend Fraction operator-(int v, const Fraction &f);

    Fraction operator*(const Fraction &f) const;
    Fraction operator*(int v) const;
    friend Fraction operator*(int v, const Fraction &f);

    Fraction operator/(const Fraction &f) const;
    Fraction operator/(int v) const;
    friend Fraction operator/(int v, const Fraction &f);
    std::string toString() const;
};


#endif //MATH_EXAM_GENERATOR_FRACTION_H
