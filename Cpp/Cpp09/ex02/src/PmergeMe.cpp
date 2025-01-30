#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << GREEN << "Default PmergeMe constructor called." << RESET << std::endl;
}

PmergeMe::~PmergeMe()
{
    std::cout << RED <<"Destructor PmergeMe called." <<  RESET << std::endl;
}

void    PmergeMe::PmergeMeExe(char* argv)
{
    std::cout << "Ciao" << std::endl;
}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return message.c_str();
}