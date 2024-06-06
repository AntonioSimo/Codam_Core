#pragma once

#include "Data.hpp"

class Serializer
{
	public: //Access specifier
	Serializer(); //Default Constructor
	Serializer(const Serializer& obj); //Copy Constructor
	Serializer& operator=(const Serializer& obj); //Copy assignment operator overload
	~Serializer(); //Destructor

	//uintptr_t serialize(Data* ptr); //Member function
	//Data* deserialize(uintptr_t raw); //Member function
};