#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 10);
        Form formA("Top Secret Form", 5, 10);

        std::cout << formA << std::endl;
        john.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try {
        Bureaucrat bob("Bob", 50);
        Form formB("Basic Form", 75, 75);

        std::cout << formB << std::endl;
        bob.signForm(formB);
        std::cout << formB << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
