#pragma once

#include <iostream>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class Data
{
private:
	uint	m_number;

public:
	Data(); //Default Constructor
	Data(const Data& obj); //Copy Constructor
	Data& operator=(const Data& obj); //Copy assignment operator overload
	~Data(); //Destructor

	void setData(uint t_number);
	uint getData();
};
