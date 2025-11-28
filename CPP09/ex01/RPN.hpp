#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <sstream>
#include <cctype>
#include <list>
#include <stack>
#include <stdexcept>
#include <iostream>

class RPN
{
private:
    std::list<std::string> tokens;
    std::stack<int> values;

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    bool validateInput(const std::string &input);
    int evaluate();
};

#endif