#pragma once

#include <iostream>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

struct Data 
{
    int m_number;

	Data();
    Data(int number);
    ~Data();
};

class Serializer
{
public: //Access specifier
	Serializer(); //Default Constructor
	Serializer(const Serializer& obj); //Copy Constructor
	Serializer& operator=(const Serializer& obj); //Copy assignment operator overload
	~Serializer(); //Destructor
	static uintptr_t serialize(Data* ptr); //Member function
	static Data* deserialize(uintptr_t raw); //Member function
};