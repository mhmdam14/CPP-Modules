#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    a.attack("Bravo");
    b.takeDamage(5);

    b.beRepaired(3);
    b.attack("Alpha");
    a.takeDamage(2);

    for (int i = 0; i < 12; i++) {
        a.attack("target");
    }

    return 0;
}
