#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

Base* generate(void)
{
    std::srand(std::time(0));
    int r = std::rand() % 3;

    switch (r)
    {
        case 0:
            std::cout << "Generated type: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated type: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated type: C" << std::endl;
            return new C();  
    }
}

void identify(Base *p)
{
    if (p == NULL)
    {
        std::cout << "Null ptr" << std:: endl;
        return;
    }

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(...){}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...){}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...){}

    std::cout << "Unknown type" << std::endl;
}