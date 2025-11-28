#include "Span.hpp"

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (numbers.size() >= N)
        throw std::out_of_range("Cannot add more numbers.");
    numbers.push_back(n);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");

    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");
    
    int minNum = *std::min_element(numbers.begin(), numbers.end());
    int maxNum = *std::max_element(numbers.begin(), numbers.end());
    
    return maxNum - minNum;
}