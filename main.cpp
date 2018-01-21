//
// Main entry of the program.
// Created by Hao He on 18-1-19.
//

#include <iostream>
#include <getopt.h>
#include <vector>

#include "Expression.h"

int main(int argc, char **argv)
{
    // A Set of default values
    const int totalDefault = 10, minOpDefault = 2, maxOpDefault = 5,
              minValDefault = -10, maxValDefault = 10;
    int total = totalDefault, minOp = minOpDefault, maxOp = maxOpDefault,
            minVal = minValDefault, maxVal = maxValDefault, flags = 0;
    int opt;
    static struct option longOptions[] = {
            {"total", required_argument, nullptr, 't'},
            {"minop", required_argument, nullptr, 'i'},
            {"maxop", required_argument, nullptr, 'o'},
            {"minval", required_argument, nullptr, 'v'},
            {"maxval", required_argument, nullptr, 'x'},
            {"add", no_argument, nullptr, 'a'},
            {"sub", no_argument, nullptr, 's'},
            {"multi", no_argument, nullptr, 'm'},
            {"div", no_argument, nullptr, 'd'},
            {"frac", no_argument, nullptr, 'f'},
            {nullptr, 0, nullptr, 0},
    };

    while ((opt = getopt_long(argc, argv, "", longOptions, nullptr)) != -1)
    {
        switch (opt)
        {
            case 't':
                total = static_cast<int>(strtol(optarg, nullptr, 10));
                if (total <= 0 || total > 100)
                {
                    std::cerr << "Invalid argument for --total! "
                              << "Setting to default value..." << std::endl;
                    total = totalDefault;
                }
                break;
            case 'i':
                minOp = static_cast<int>(strtol(optarg, nullptr, 10));
                if (minOp < 2 || minOp > 100)
                {
                    std::cerr << "Invalid argument for --minop! "
                              << "Setting to default value..." << std::endl;
                    minOp = minOpDefault;
                }
                break;
            case 'o':
                maxOp = static_cast<int>(strtol(optarg, nullptr, 10));
                if (maxOp < 2 || maxOp > 100)
                {
                    std::cerr << "Invalid argument for --maxop! "
                              << "Setting to default value..." << std::endl;
                    maxOp = maxOpDefault;
                }
                break;
            case 'v':
                minVal = static_cast<int>(strtol(optarg, nullptr, 10));
                break;
            case 'x':
                maxVal = static_cast<int>(strtol(optarg, nullptr, 10));
                break;
            case 'a':
                flags |= ALLOW_ADD;
                break;
            case 's':
                flags |= ALLOW_SUB;
                break;
            case 'm':
                flags |= ALLOW_MULTI;
                break;
            case 'd':
                flags |= ALLOW_DIV;
                break;
            case 'f':
                flags |= ALLOW_FRACTION;
                break;
            default:
                break;
        }
    }

    if (maxOp < minOp)
    {
        std::swap(minOp, maxOp);
    }
    if (maxVal < minVal)
    {
        std::swap(maxVal, minVal);
    }
    if (flags == 0)
    {
        flags = ALLOW_ADD|ALLOW_SUB|ALLOW_MULTI|ALLOW_DIV|ALLOW_FRACTION;
    }

    std::vector<Expression*> expressions;
    for (int i = 0; i < total; ++i)
    {
        expressions.push_back(generateExpression(minOp, maxOp, minVal, maxVal, flags));
    }

    using std::cout;
    using std::endl;
    cout << "Math Exam(100pt)" << endl;
    cout << total << " questions in total. "
         << 100/total << " points each. " << endl;
    for (int i = 1; i <= total; ++i)
    {
        cout << i << ". " << expressions[i - 1]->toString() << "=" << endl;
    }

    cout << endl << endl;
    cout << "Answer Sheet" << endl;
    for (int i = 1; i <= total; ++i)
    {
        cout << i << ". " << expressions[i - 1]->evaluate().toString() << endl;
    }

    for (int i = 0; i < total; ++i)
    {
        delete expressions[i];
    }
    return 0;
}