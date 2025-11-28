#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int N;
    std::vector<int> numbers;
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename It>
    void addNumbers(It begin, It end)
    {
        for (It it = begin; it != end; it++)
        {
            if (numbers.size() >= N)
                throw std::out_of_range("Cannot add more numbers.");
            numbers.push_back(*it);
        }
    }
};

#endif