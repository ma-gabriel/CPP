

#include "RPN.hpp"
#include <cstdlib>
#include <string>

RPN::RPN(void){}
RPN::RPN(const RPN &){}
RPN::~RPN(){}
RPN &RPN::operator=(const RPN &){ return *this;}


int RPN::process(char *argv)
{
    std::stack<int> data;
    int res;
    while (argv[0] == ' ')
        argv++;
    if (std::string("+-*/").find(argv[0]) != std::string::npos)
        throw std::string("need to start with a number");
    res = argv[0] - '0';
    for (size_t i = 1; argv[i]; i++)
    {
        if (std::string("0123456789 +-*/").find(argv[i]) == std::string::npos)
            throw std::string("bad format, we only take space, numbers, and +-/*");
        switch (argv[i])
        {
            case '+':
                if (data.empty())
                    throw std::string("tried doing the operator + with not enough numbers before");
                if (__builtin_sadd_overflow (res, data.top(), &res))
                    throw std::string("overflow of the int");
                data.pop();
                break;

            case '-':
                if (data.empty())
                    throw std::string("tried doing the operator - with not enough numbers before");
                if (__builtin_ssub_overflow (res, data.top(), &res))
                    throw std::string("overflow of the int");
                data.pop();
                break;
            
            case '*':
                if (data.empty())
                    throw std::string("tried doing the operator * with not enough numbers before");
                if (__builtin_smul_overflow (res, data.top(), &res))
                    throw std::string("overflow of the int");
                data.pop();
                break;
            
            case '/':
                if (data.empty())
                    throw std::string("tried doing the operator - with not enough numbers before");
                res = res / data.top();
                data.pop();
                break;
            
            case ' ':
                break;
            default:
                data.push(argv[i] - '0');
                break;
        }
    }
    if (!data.empty())
        throw std::string("too many numbers");
    return res;

}