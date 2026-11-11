#include "RPN.hpp"
static bool ftIsDigit(char c) { return (c >= '0' && c <= '9'); }
static bool ftIsOperand(char c) { return (c == '/' || c == '*' || c == '+' || c == '-'); }
static bool ftIsSpace(char c) { return (c == ' '); }
void    solve(char *argument)
{
    std::stack<int>     postfix;
    int                 result = 0;
    int                 temp = 0;
    for (size_t i = 0; argument[i] != '\0'; i++)
    {
        if (ftIsSpace(argument[i]))
            continue;
        if (ftIsDigit(argument[i]))
        {
            if (argument[i + 1] != '\0' && !ftIsSpace(argument[i + 1]))
                throw std::runtime_error("missing space");
            else
                postfix.push(argument[i] - '0');
        }
        else if (ftIsOperand(argument[i]))
        {
            if (argument[i + 1] != '\0' && !ftIsSpace(argument[i + 1]))
                throw std::runtime_error("missing space");
            else
            {
                if (postfix.empty())
                    throw std::runtime_error("missing operator");
                temp = postfix.top();
                postfix.pop();
                if (postfix.empty())
                    throw std::runtime_error("missing operator");
                if (argument[i] == '+')
                    result = postfix.top() + temp;
                else if (argument[i] == '-')
                    result = postfix.top() - temp;
                else if (argument[i] == '/')
                {
                    if (temp == 0)
                        throw std::runtime_error("world implotion");
                    result = postfix.top() / temp;
                }
                else if (argument[i] == '*')
                    result = postfix.top() * temp;
                postfix.pop();
                postfix.push(result);
            }
        }
        else
            throw std::runtime_error("invalid character");
    }
    if (postfix.size() == 1)
        std::cout << postfix.top() << std::endl;
    else
        throw std::runtime_error("inbalance between operands and operators");
}