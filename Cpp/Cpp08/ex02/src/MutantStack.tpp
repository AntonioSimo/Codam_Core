#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "Default MutantStack constructor called." << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "Destructor MutantStack called." << std::endl;
}
