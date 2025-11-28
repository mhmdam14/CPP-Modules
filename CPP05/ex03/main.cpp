#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Intern intern;

        std::cout << "\n=== Creating Forms via Intern ===" << std::endl;

        AForm* shrubForm = intern.makeForm("shrubbery creation", "Home");
        AForm* roboForm = intern.makeForm("robotomy request", "Bender");
        AForm* pardonForm = intern.makeForm("presidential pardon", "Arthur Dent");
        AForm* badForm = intern.makeForm("galactic license", "Nobody");

        std::cout << "\n=== Signing and Executing Valid Forms ===" << std::endl;

        if (shrubForm) {
            boss.signForm(*shrubForm);
            boss.executeForm(*shrubForm);
        }

        if (roboForm) {
            boss.signForm(*roboForm);
            boss.executeForm(*roboForm);
        }

        if (pardonForm) {
            boss.signForm(*pardonForm);
            boss.executeForm(*pardonForm);
        }

        std::cout << "\n=== Cleaning up dynamically allocated forms ===" << std::endl;
        delete shrubForm;
        delete roboForm;
        delete pardonForm;
        delete badForm;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
