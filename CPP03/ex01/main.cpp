#include "ScavTrap.hpp"

int main() {
    std::cout << "---- ClapTrap tests ----" << std::endl;
    ClapTrap clap("Clap");
    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n---- ScavTrap tests ----" << std::endl;
    ScavTrap scav("Scav");
    scav.attack("enemy");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n---- Destructor order ----" << std::endl;
    return 0;
}
