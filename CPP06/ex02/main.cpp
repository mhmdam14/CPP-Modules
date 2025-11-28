#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    Base* base = generate();
    std::cout << std::endl;

    std::cout << "Identify using pointer: ";
    identify(base);

    std::cout << "Identify using reference: ";
    identify(*base);

    delete base;
    return 0;
}
