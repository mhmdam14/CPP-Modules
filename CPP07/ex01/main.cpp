#include "Iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"one", "two", "three"};

    std::cout << "Original intArray: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    iter(intArray, 5, increment<int>);

    std::cout << "After increment: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}