
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

static void convert_c(char *);
static void convert_i(char *);
static void convert_d(std::string);
static void convert_f(std::string);



void ScalarConverter::convert(std::string s)
{
    convert_c(const_cast<char *>(s.c_str()));
    convert_i(const_cast<char *>(s.c_str()));
    convert_f(s);
    convert_d(s);
}


static void convert_i(char *s)
{
    char *end;
    int i = strtol(s, &end, 10);
    if (s == end)
        std::cout << "int: impossible\n";
    else 
        std::cout << "int: " << i << "\n";
}

static void convert_c(char *s)
{
    char *end;
    char c = strtol(s, &end, 10);
    if (s == end)
        std::cout << "char: impossible\n";
    else if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: non displayable\n";
}

static void convert_f(std::string s)
{
    float f;
    std::cout.precision(1);
    std::cout << std::fixed;
    errno = 0;
    if (std::stringstream(s) >> f)
        std::cout << "float: " << f << "f\n";
    else if (errno == ERANGE && f == std::numeric_limits<float>::max())
        std::cout << "float: +inff\n";
    else if (errno == ERANGE && f == -std::numeric_limits<float>::max())
        std::cout << "float: -inff\n";
    else
        std::cout << "float: nanf\n";
}

static void convert_d(std::string s)
{   
    double d;
    std::cout.precision(1);
    std::cout << std::fixed;
    errno = 0;
    if (std::stringstream(s) >> d)
        std::cout << "double: " << d << std::endl;
    else if (errno == ERANGE && d == std::numeric_limits<double>::max())
        std::cout << "double: +inf" << std::endl;
    else if (errno == ERANGE && d == -std::numeric_limits<double>::max())
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: nan" << std::endl;
}
