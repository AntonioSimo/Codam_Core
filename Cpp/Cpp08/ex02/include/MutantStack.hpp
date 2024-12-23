#pragma once

#include <iostream>
#include <iterator>
#include <stack>

#define GREEN	"\033[32m"
#define RED     "\033[31m"
#define RESET	"\033[0m"

template<typename T>
class MutantStack : public std::stack<T>
{
    public: //Access specifier
        using iterator = typename std::stack<T>::container_type::iterator;

        MutantStack(); //Default Constructor
        ~MutantStack(); //Destructor

        iterator begin()
        {
            return(this->c.begin());
        }
        
        iterator end()
        {
            return(this->c.end());
        }
};

#include "../src/MutantStack.tpp"