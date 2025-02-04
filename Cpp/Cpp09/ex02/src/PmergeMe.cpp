#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << GREEN << "Default PmergeMe constructor called." << RESET << std::endl;
}

PmergeMe::~PmergeMe()
{
    std::cout << RED <<"Destructor PmergeMe called." <<  RESET << std::endl;
}

void    PmergeMe::PmergeMeExe(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        try
        {
            if (!isdigit(*argv[i]))
                throw PmergeMe::PmergeMeException("Invalid argument.");
            int number = std::stoi(argv[i]);
            if (number <= 0)
                throw PmergeMe::PmergeMeException("Invalid argument.");
            if (std::find(_container.begin(), _container.end(), number) != _container.end()) 
                throw PmergeMe::PmergeMeException("Duplicate found.");
            _container.push_back(number);
        }
        catch(const PmergeMe::PmergeMeException& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
         catch (const std::out_of_range& e)
        {
            std::cerr << "Invalid argument: Number out of range." << std::endl;
            return;
        }
    }

    std::cout << "Before: ";
    for (auto i = _container.begin(); i < _container.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    fordJohnsonSort(_container);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "After: ";
    for (auto i = _container.begin(); i < _container.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _container.size() << " elements with std::vector : " << duration.count() * 1000000 << " us" << std::endl;
}

void PmergeMe::fordJohnsonSort(std::vector<int>& container) 
{
    if (container.size() <= 1) 
        return;
    std::vector<int> sorted;
    for (size_t i = 0; i < container.size(); ++i) 
    {
        int current = container[i];
        auto it = std::lower_bound(sorted.begin(), sorted.end(), current);
        sorted.insert(it, current);
    }
    container = sorted;
}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return message.c_str();
}