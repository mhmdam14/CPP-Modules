#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("DefaultClap"), hit_points(10), energy_points(10), attack_damage(10)
{
    std::cout << "ClapTrap " << name << " default constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hit_points(10), energy_points(10), attack_damage(10)
{
    std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (!energy_points || !hit_points)
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left!" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hit_points -= amount;
    if (hit_points < 0)
        hit_points = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage! Remaining HP: " << hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!energy_points || !hit_points)
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left!" << std::endl;
        return;
    }
    energy_points--;
    hit_points += amount;
    std::cout << "ClapTrap " << name << " repairs itself with " << amount << " HP! Total HP: " << hit_points << std::endl;

}