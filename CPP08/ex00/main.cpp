#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    try
    {
        int arr_vec[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(arr_vec, arr_vec + 5);
        std::cout << "Vector: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << " ";
        std::cout << "\nFinding 3 in vector: " << *easyfind(vec, 3) << std::endl;

        int arr_lst[] = {10, 20, 30, 40, 50};
        std::list<int> lst(arr_lst, arr_lst + 5);
        std::cout << "List: ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
            std::cout << *it << " ";
        std::cout << "\nFinding 20 in list: " << *easyfind(lst, 20) << std::endl;

        int arr_deq[] = {100, 200, 300, 400, 500};
        std::deque<int> deq(arr_deq, arr_deq + 5);
        std::cout << "Deque: ";
        for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
            std::cout << *it << " ";
        std::cout << "\nFinding 400 in deque: " << *easyfind(deq, 400) << std::endl;

        std::cout << "\nAttempting to find 99 in vector: ";
        easyfind(vec, 99);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
