
#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <stdlib.h>
#include <limits>
#include <cerrno>

ScalarConverter::ScalarConverter()
{}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &){
    return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter const &)
{}
ScalarConverter::~ScalarConverter()
{}

static double findValue(std::string);
static void convert_c(double);
static void convert_i(double);
static void convert_d(double);
static void convert_f(double);



void ScalarConverter::convert(std::string s)
{
    double d = findValue(s);
    convert_c(d);
    convert_i(d);
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    convert_f(d);
    convert_d(d);
}

static void convert_c(double d)
{

    if (d != d)
        std::cout << "char: impossible\n";
    else if (d > std::numeric_limits<char>::max())
        std::cout << "char: overflowed\n";
    else if (d < std::numeric_limits<char>::min())
        std::cout << "char: underflowed\n";
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    else
        std::cout << "int: Non displayable\n";
}

static void convert_i(double d)
{
    if (d != d)
        std::cout << "int: impossible\n";
    else if (d > std::numeric_limits<int>::max())
        std::cout << "int: overflowed\n";
    else if (d < std::numeric_limits<int>::min())
        std::cout << "int: underflowed\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
}

static void convert_f(double d)
{
    float f = static_cast<float>(d);
    std::cout << "float: " << f << "f\n";
}

static void convert_d(double d)
{
    std::cout << "double: " << d << std::endl;
}

static double findValue(std::string s)
{
    double d;
    errno = 0;
    if (std::stringstream(s) >> d)
        return d;
    if (errno == ERANGE && d == std::numeric_limits<double>::max())
        return std::numeric_limits<double>::infinity();
    if (errno == ERANGE && d == -std::numeric_limits<double>::max())
        return -std::numeric_limits<double>::infinity();
    return std::numeric_limits<double>::quiet_NaN();
}
