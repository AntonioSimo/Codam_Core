#pragma once

#include <iostream>
#include <vector>

class Span
{
private: //Access specifier
    unsigned int     m_numbers; //Attribute
    std::vector<int>   m_container; //Attribute

public: //Access specifier
    Span(); //Default Constructor
    Span(unsigned int t_size); //Parameterized Constructor
    Span(const Span& obj); //Copy Constructor
    Span& operator=(const Span& ob); //Copy assignment operator overload
    ~Span(); //Destructor
    void addNumber(int x); //Member function
    std::vector<int>& getContainer(); // Member function

};

template <typename T>
void printValue(const T& container)
{
    for (auto i = container.begin(); i != container.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}