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
        if (!isdigit(*argv[i]))
            throw PmergeMe::PmergeMeException("Invalid argument.");
        _container.push_back(std::stoi(argv[i]));
    }

    std::cout << "Before: ";
    for (auto i = _container.begin(); i < _container.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    fordJohnsonSort(_container);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& vec) 
{
    std::cout << "After: ";
    for (auto i = _container.begin(); i < _container.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return message.c_str();
}