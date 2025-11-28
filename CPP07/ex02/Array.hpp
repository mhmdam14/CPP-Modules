#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class Array
{
private:
	T* data;
	unsigned int arr_size;
public:
	Array() : data(NULL), arr_size(0) {}

	Array(unsigned int n) : data(NULL), arr_size(n)
	{
		if (n > 0)
			data = new T[n]();
	}

	Array(const Array& other) : data(NULL), arr_size(other.arr_size)
	{
		if (arr_size > 0)
		{
			data = new T[arr_size];
			for (unsigned int i = 0; i < arr_size; i++)
				data[i] = other.data[i];
		}
	}

	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] data;
			arr_size = other.arr_size;
			data = NULL;
			if (arr_size > 0)
			{
				data = new T[arr_size];
				for (unsigned int i = 0; i < arr_size; i++)
					data[i] = other.data[i];
			}
		}
		return *this;
	}

	~Array()
	{
		delete[] data;
	}

	T& operator[](unsigned int i)
	{
		if (i >= arr_size)
			throw std::out_of_range("Index out of bounds");
		return data[i];
	}

	const T& operator[](unsigned int i) const
	{
		if (i >= arr_size)
			throw std::out_of_range("Index out of bounds");
		return data[i];
	}

	unsigned int size() const
	{
		return arr_size;
	}
};


#endif