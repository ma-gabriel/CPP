

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
    while (argv[0] == ' ')
        argv++;
    if (std::string("+-*/").find(argv[0]) != std::string::npos)
        throw std::string("need to start with a number");
    for (size_t i = 0; argv[i]; i++)
    {
        int res;
        if (std::string("0123456789 +-*/").find(argv[i]) == std::string::npos)
            throw std::string("bad format, we only take space, numbers, and +-/*");
        switch (argv[i])
        {
            case '+':
                if (data.size() < 2)
                    throw std::string("tried doing the operator + with not enough numbers before");
                res = data.top();
                data.pop();
                if (__builtin_sadd_overflow (res, data.top(), &res))
                    throw std::string("overflow of the int");
                data.pop();
                data.push(res);
                break;

            case '-':
                if (data.size() < 2)
                    throw std::string("tried doing the operator - with not enough numbers before");
                res = data.top();
                data.pop();
                if (__builtin_ssub_overflow (data.top(), res, &res))
                    throw std::string("overflow of the int");
                data.pop();
                data.push(res);
                break;
            
            case '*':
                if (data.size() < 2)
                    throw std::string("tried doing the operator * with not enough numbers before");
                res = data.top();
                data.pop();
                if (__builtin_smul_overflow (res, data.top(), &res))
                    throw std::string("overflow of the int");
                data.pop();
                data.push(res);
                break;
            
            case '/':
                if (data.size() < 2)
                    throw std::string("tried doing the operator - with not enough numbers before");
                res = data.top();
                data.pop();
                res = data.top() / res;
                data.pop();
                data.push(res);
                break;
            
            case ' ':
                break;
            default:
                data.push(argv[i] - '0');
                break;
        }
    }
    if (data.size() != 1)
        throw std::string("too many numbers");
    return data.top();

}