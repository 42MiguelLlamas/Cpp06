#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &src);

    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
};

#endif