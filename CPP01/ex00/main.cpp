#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    std::cout << "Creating zombie on heap:" << std::endl;
    Zombie* z = newZombie("heap");
    z->announce();
    delete z;
    std::cout << "Creating zombie on stack:" << std::endl;
    randomChump("stack");
    return 0;
}