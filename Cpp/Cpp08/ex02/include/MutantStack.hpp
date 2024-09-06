#pragma once

#include <iostream>
#include <stack>
#include "../src/MutantStack.tpp"

class MutantStack
{
    private:


    public: //Access specifier
        MutantStack(); //Default Constructor
        MutantStack(unsigned int t_size); //Parameterized Constructor
        MutantStack(const MutantStack& obj); //Copy Constructor
        MutantStack& operator=(const MutantStack& ob); //Copy assignment operator overload
        ~MutantStack(); //Destructor
};