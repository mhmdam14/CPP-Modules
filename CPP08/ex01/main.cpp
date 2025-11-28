#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    Span sp2 = Span(10);
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> nums(arr, arr + 5);
    sp2.addNumbers(nums.begin(), nums.end());

    std::cout << "Shortest Span in sp2: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span in sp2: " << sp2.longestSpan() << std::endl;

    return 0;
}
