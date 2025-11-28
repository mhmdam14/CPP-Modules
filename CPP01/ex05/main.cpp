#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG Level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "INFO Level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "WARNING Level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "ERROR Level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Trying Invalid level:" << std::endl;
    harl.complain("RANDOM");
    std::cout << std::endl;

    return 0;
}
