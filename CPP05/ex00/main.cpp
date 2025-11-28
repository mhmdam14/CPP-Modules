#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat Mhmd("Mhmd", 2);
        std::cout << Mhmd << std::endl;

        Mhmd.incrementGrade();
        std::cout << Mhmd << std::endl;

        Mhmd.incrementGrade();
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat Mostafa("Mostafa", 150);
        std::cout << Mostafa << std::endl;
		Mostafa.decrementGrade();
        std::cout << Mostafa << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
