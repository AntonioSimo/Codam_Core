#pragma once

#include <iostream>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

template <typename T>
class Array
{
	private:
		T* m_elements;
		unsigned int m_size;

   	public:
		Array() : m_elements(nullptr), m_size(0) //Default constructor
		{
			std::cout << "Default Array templates constructor called." << std::endl;
		}

		Array(unsigned int n) : m_elements(nullptr), m_size(n) //Parameteruzed constructor
		{
			m_elements = new T[n]();

			std::cout << GREEN <<  "Parameterized Array templates constructor called." << RESET << std::endl;
		}

		Array(const Array& obj) : m_elements(nullptr), m_size(obj.m_size) //Copy Constructor
		{
        	m_elements = new T[m_size];
        	for (unsigned int i = 0; i < m_size; ++i)
            	m_elements[i] = obj.m_elements[i];

        	std::cout << "Copy Array template constructor called." << std::endl;
    	}

    	Array& operator=(const Array& obj) //Copy assignment operator overload
		{
        	if (this != &obj) 
			{
            	delete[] m_elements;
            	m_size = obj.m_size;
            	m_elements = new T[m_size]();

            	for (unsigned int i = 0; i < m_size; ++i) 
                	m_elements[i] = obj.m_elements[i];
        }

        	std::cout << "Copy Array assignment operator called." << std::endl;

        	return *this;
    	}

		T& operator[](unsigned int index) //Access operator
		{
        	if (index >= m_size)
            	throw std::out_of_range("Index out of range");

        	return m_elements[index];
    	}

		~Array() //Destructtor
		{
			delete[] m_elements;
			std::cout << RED << "Default Array templates destructor called." << RESET << std::endl;
    	}

		unsigned int size() //Member function
		{
			return (this->m_size);	
		}
};
