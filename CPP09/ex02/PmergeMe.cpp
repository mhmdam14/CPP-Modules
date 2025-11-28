#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : comparisons(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

// INPUT:

bool isDuplicate(const std::vector<int> &v, long nb)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == nb)
            return true;
    }
    return false;
}

bool PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string s = argv[i];

        if (s.empty())
            return false;

        for (size_t j = 0; j < s.length(); j++)
        {
            if (!isdigit(s[j]))
                return false;
        }

        long nb = std::strtol(s.c_str(), NULL, 10);
        if (nb < 0 || nb > INT_MAX || isDuplicate(vec, nb))
            return false;

        vec.push_back(nb);
        deq.push_back(nb);
    }
    return true;
}

// VECTOR SORTING:

void PmergeMe::sortVector(std::vector<int> &v)
{
    size_t n = v.size();

    if (n <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;

    int lastElement = -1;
    bool isOdd = (n % 2 == 1);

    if (isOdd)
        lastElement = v.back();

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        comparisons++;
        if (v[i] > v[i + 1])
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        else
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }

    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].second);

    sortVector(larger);

    std::vector<int> main;
    std::vector<int> pending;
    std::vector<int> positions;
    std::vector<int> smaller;

    for (size_t i = 0; i < larger.size(); i++)
    {
        int val = larger[i];
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].second == val)
            {
                smaller.push_back(pairs[j].first);
                pairs[j].second = -1;
                break;
            }
        }
    }

    main.push_back(smaller[0]);
    for (size_t i = 0; i < larger.size(); i++)
    {
        main.push_back(larger[i]);
        positions.push_back(main.size() - 1);
    }

    for (size_t i = 1; i < smaller.size(); i++)
        pending.push_back(smaller[i]);

    if (isOdd)
        pending.push_back(lastElement);

    std::vector<int> jacob = generateJacobsthalSequence<std::vector<int> >(pending.size() + 2);

    size_t k = 1;
    size_t inserted_count = 0;

    while (inserted_count < pending.size())
    {
        int end = jacob[k];
        int start = jacob[k - 1];

        if (end > (int)pending.size() + 1)
            end = pending.size() + 1;

        for (int i = end; i > start; i--)
        {
            int pending_index = i - 2;

            if (pending_index >= 0 && pending_index < (int)pending.size())
            {
                int val = pending[pending_index];

                int limit_index;
                if (pending_index < (int)smaller.size() - 1)
                    limit_index = positions[pending_index + 1];
                else
                    limit_index = main.size();

                int pos = binarySearch(main, val, limit_index);
                main.insert(main.begin() + pos, val);
                inserted_count++;

                for (size_t p = 0; p < positions.size(); p++)
                {
                    if (positions[p] >= pos)
                        positions[p]++;
                }
            }
        }
        k++;
    }

    v = main;
}

// DEQUE SORTING:

void PmergeMe::sortDeque(std::deque<int> &d)
{
    size_t n = d.size();

    if (n <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;

    int lastElement = -1;
    bool isOdd = (n % 2 == 1);

    if (isOdd)
        lastElement = d.back();

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        comparisons++;
        if (d[i] > d[i + 1])
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
        else
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
    }

    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].second);

    sortDeque(larger);

    std::deque<int> main;
    std::deque<int> pending;
    std::deque<int> positions;
    std::deque<int> smaller;

    for (size_t i = 0; i < larger.size(); i++)
    {
        int a_val = larger[i];
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].second == a_val)
            {
                smaller.push_back(pairs[j].first);
                pairs[j].second = -1;
                break;
            }
        }
    }

    main.push_back(smaller[0]);
    for (size_t i = 0; i < larger.size(); i++)
    {
        main.push_back(larger[i]);
        positions.push_back(main.size() - 1);
    }

    for (size_t i = 1; i < smaller.size(); i++)
        pending.push_back(smaller[i]);

    if (isOdd)
        pending.push_back(lastElement);

    std::deque<int> jacob = generateJacobsthalSequence<std::deque<int> >(pending.size() + 2);

    size_t k = 1;
    size_t inserted_count = 0;

    while (inserted_count < pending.size())
    {
        int end = jacob[k];
        int start = jacob[k - 1];

        if (end > (int)pending.size() + 1)
            end = pending.size() + 1;

        for (int i = end; i > start; i--)
        {
            int pending_index = i - 2;

            if (pending_index >= 0 && pending_index < (int)pending.size())
            {
                int val = pending[pending_index];

                int limit_index;
                if (pending_index < (int)smaller.size() - 1)
                    limit_index = positions[pending_index + 1];
                else
                    limit_index = main.size();

                int pos = binarySearch(main, val, limit_index);
                main.insert(main.begin() + pos, val);
                inserted_count++;

                for (size_t p = 0; p < positions.size(); p++)
                {
                    if (positions[p] >= pos)
                        positions[p]++;
                }
            }
        }
        k++;
    }

    d = main;
}

// RUN:

void PmergeMe::run(int argc, char **argv)
{
    if (!parseInput(argc, argv))
    {
        std::cerr << "Error: Invalid input." << std::endl;
        return;
    }

    // size_t old_size = vec.size();
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::clock_t start = std::clock();
    sortVector(vec);
    std::clock_t end = std::clock();
    double vec_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // std::cout << "Total comparisons in vector: " << comparisons << std::endl;

    // if (isSorted(vec) && vec.size() == old_size && comparisons <= 66)
    //     std::cout << "✅" << std::endl;
    // else
    //     std::cout << "❌" << std::endl;

    comparisons = 0;

    // old_size = deq.size();
    // std::cout << "Unsorted deque: ";
    // for (size_t i = 0; i < deq.size(); i++)
    //     std::cout << deq[i] << " ";
    // std::cout << std::endl;

    start = std::clock();
    sortDeque(deq);
    end = std::clock();
    double deq_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    // std::cout << "Sorted deque: ";
    // for (size_t i = 0; i < deq.size(); i++)
    //     std::cout << deq[i] << " ";
    // std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vec_time << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deq_time << " us" << std::endl;

    // std::cout << "Total comparisons in deque: " << comparisons << std::endl;

    // if (isSorted(deq) && deq.size() == old_size && comparisons <= 66)
    //     std::cout << "✅" << std::endl;
    // else
    //     std::cout << "❌" << std::endl;
}
