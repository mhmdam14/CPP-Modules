#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    (void)other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

RPN::~RPN() {}

static bool isOpChar(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::validateInput(const std::string &input)
{
    tokens.clear();

    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
        tokens.push_back(token);

    if (tokens.empty())
        return false;

    for (std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        const std::string &s = *it;

        if (s.length() > 2)
            return false;

        char c;
        if (s.length() == 1)
            c = s[0];
        else
        {
            if ((s[0] != '-' && s[0] != '+') || !isdigit(s[1]))
                return false;
            c = s[1];
        }
        if (!isdigit(c) && !isOpChar(c))
            return false;
    }

    return true;
}

int RPN::evaluate()
{
    while (!values.empty())
        values.pop();

    int res = 0;

    for (std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        char c;

        if ((*it).length() == 1)
            c = (*it)[0];
        else
            c = (*it)[1];

        if (isdigit(c))
        {
            int nb = c - '0';
            if ((*it).length() == 2 && (*it)[0] == '-')
                nb *= -1;
            values.push(nb);
        }

        else if (isOpChar(c))
        {
            if (values.size() < 2)
                throw std::runtime_error("Error");

            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();

            if (c == '/' && b == 0)
                throw std::runtime_error("Error");

            switch (c)
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
            }

            values.push(res);
        }
    }

    if (values.size() != 1)
        throw std::runtime_error("Error");

    return values.top();
}
