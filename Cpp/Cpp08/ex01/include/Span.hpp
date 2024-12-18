#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

class Span
{
private: //Access specifier
    unsigned int     m_size; //Attribute
    std::vector<int>   m_container; //Attribute

public: //Access specifier
    Span(); //Default Constructor
    Span(unsigned int t_size); //Parameterized Constructor
    Span(const Span& obj); //Copy Constructor
    Span& operator=(const Span& ob); //Copy assignment operator overload
    ~Span(); //Destructor

    void addNumber(int x); //Member function
    void addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);  //Member function
    std::vector<int>& getContainer(); //Member function
    int longestSpan(); //Member function
    int shortestSpan(); //Member function

    template <typename T>
    void printValue(const T& container)
    {
        for (auto i = container.begin(); i != container.end(); i++)
        {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }
};


