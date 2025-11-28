#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <list of positive integers>" << std::endl;
        return 1;
    }
    
    PmergeMe pmergeMe;
    pmergeMe.run(argc, argv);

    return 0;
}