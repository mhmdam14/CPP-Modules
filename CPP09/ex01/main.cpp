#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn;

        if (!rpn.validateInput(argv[1]))
            throw std::runtime_error("Error");

        int result = rpn.evaluate();
        std::cout << result << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
