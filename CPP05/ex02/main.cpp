#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        bob.signForm(shrub);
        bob.signForm(robo);
        bob.signForm(pardon);

        bob.executeForm(shrub);
        bob.executeForm(robo);
        bob.executeForm(pardon);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}
