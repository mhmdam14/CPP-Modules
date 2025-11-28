#include "Serializer.hpp"

int main() {
    Data data;
    data.n = 42;
    data.str = "Example Data";
    data.v = 3.14;

    std::cout << "Original Data address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized v (uintptr_t): " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserialized << std::endl;

    if (deserialized == &data)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers don’t match." << std::endl;

    std::cout << "\nDeserialized Data content:" << std::endl;
    std::cout << "  n: " << deserialized->n << std::endl;
    std::cout << "  str: " << deserialized->str << std::endl;
    std::cout << "  v: " << deserialized->v << std::endl;

    return 0;
}
