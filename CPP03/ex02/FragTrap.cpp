#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag") {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << name << " default constructed" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " constructed" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap " << name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (!hit_points || !energy_points)
    {
        std::cout << "FragTrap " << name << " has no energy or hit points left!" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a positive high-five" << std::endl;
}