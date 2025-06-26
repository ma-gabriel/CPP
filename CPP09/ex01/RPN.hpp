#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN
{
    public:
        static int process(char *argv);
    private:
        RPN(void);
        RPN(const RPN &);
        virtual ~RPN() = 0;
        RPN &operator=(const RPN &ref);
};


#endif