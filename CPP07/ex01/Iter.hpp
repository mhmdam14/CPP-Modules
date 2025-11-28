#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *arr, std::size_t length, F func)
{
	for (std::size_t i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T>
void printElement(const T &elem)
{
    std::cout << elem << " ";
}

template <typename T>
void increment(T &elem)
{
    ++elem;
}

#endif