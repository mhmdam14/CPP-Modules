#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;

    std::cout << "\n----- Testing WrongAnimal / WrongCat -----" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCatPtr = new WrongCat();
    std::cout << wrongCatPtr->getType() << " " << std::endl;
    wrongMeta->makeSound();
    wrongCatPtr->makeSound();
    
    const WrongCat* wrongCat = new WrongCat();
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCatPtr;
    delete wrongCat;

    return 0;
}
