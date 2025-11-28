#include "Array.hpp"
#include <string>

int main() {
    try {
        std::cout << "Testing default constructor\n";
        Array<int> a;
        std::cout << "Size of a: " << a.size() << "\n";

        std::cout << "\nTesting constructor with size\n";
        Array<int> b(5);
        std::cout << "Size of b: " << b.size() << "\n";
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" << i << "] = " << b[i] << "\n";

        std::cout << "\nTesting element assignment\n";
        for (unsigned int i = 0; i < b.size(); ++i)
            b[i] = i * 10;
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" << i << "] = " << b[i] << "\n";

        std::cout << "\nTesting copy constructor\n";
        Array<int> c = b;
        std::cout << "Changing c[0] = 999\n";
        c[0] = 999;
        std::cout << "c[0] = " << c[0] << ", b[0] = " << b[0] << "\n";

        std::cout << "\nTesting assignment operator\n";
        Array<int> d;
        d = b;
        std::cout << "Changing d[1] = 777\n";
        d[1] = 777;
        std::cout << "d[1] = " << d[1] << ", b[1] = " << b[1] << "\n";

        std::cout << "\nTesting with std::string type\n";
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "World";
        words[2] = "!";
        for (unsigned int i = 0; i < words.size(); ++i)
            std::cout << words[i] << " ";
        std::cout << "\n";

        std::cout << "\nTesting out of bounds\n";
        std::cout << b[10] << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
