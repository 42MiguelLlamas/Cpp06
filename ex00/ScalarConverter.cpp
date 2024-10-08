#include "ScalarConverter.hpp"

static bool isSpecialLiteral(const std::string &literal)
{
    return (literal == "+inf" || literal == "-inf" || literal == "nan" ||
            literal == "+inff" || literal == "-inff" || literal == "nanf");
}

void ScalarConverter::convert(const std::string &literal)
{
    double value = 0.0;

    if (isSpecialLiteral(literal))
    {
        if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::numeric_limits<double>::quiet_NaN();

        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        value = std::strtof(literal.c_str(), NULL);
    else if (isDouble(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "Invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

bool ScalarConverter::isChar(const std::string &literal)
{
    return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *end;
    long value = std::strtol(literal.c_str(), &end, 10);
    return (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    return (literal.find('f') != std::string::npos && std::strtof(literal.c_str(), NULL) != HUGE_VALF);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    return (literal.find('.') != std::string::npos && std::strtod(literal.c_str(), NULL) != HUGE_VAL);
}

void ScalarConverter::printChar(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 255)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    std::cout << "float: " << static_cast<float>(value);
    if (std::isnan(value) || std::isinf(value))
        std::cout << "f" << std::endl;
    else
        std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: " << value << std::endl;
}