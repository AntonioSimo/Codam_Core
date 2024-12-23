#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
    std::cout << GREEN << "Default MutantStack constructor called." << RESET << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << RED << "Destructor MutantStack called." << RESET << std::endl;
}
