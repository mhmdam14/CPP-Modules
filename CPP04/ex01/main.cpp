#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n---- Testing makeSound ----" << std::endl;
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();

    std::cout << "\n---- Testing deep copy ----" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "Chase the cat");
    Dog* copiedDog = new Dog(*originalDog);
    copiedDog->getBrain()->setIdea(0, "Sleep");

    std::cout << "Original Dog idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;

    delete originalDog;
    delete copiedDog;

    std::cout << "\n---- Deleting all animals ----" << std::endl;
    for (int i = 0; i < SIZE; i++)
        delete animals[i];
    return 0;
}
