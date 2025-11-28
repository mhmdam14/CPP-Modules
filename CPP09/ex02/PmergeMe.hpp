#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <utility>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::deque<int> deq;
    int comparisons;

    // template <typename T>
    // static bool isSorted(const T &v)
    // {
    //     for (size_t i = 1; i < v.size(); i++)
    //     {
    //         if (v[i - 1] > v[i])
    //             return false;
    //     }
    //     return true;
    // }

    template <typename T>
    int binarySearch(const T &arr, int val, int right)
    {
        int left = 0;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            comparisons++;
            if (arr[mid] > val)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    template <typename Container>
    Container generateJacobsthalSequence(size_t n)
    {
        Container jacob;
        jacob.push_back(1);
        jacob.push_back(3);

        while (jacob.back() < (int)n)
            jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

        return jacob;
    }

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseInput(int argc, char **argv);

    void sortVector(std::vector<int> &v);
    void sortDeque(std::deque<int> &d);

    void run(int argc, char **argv);
};

#endif