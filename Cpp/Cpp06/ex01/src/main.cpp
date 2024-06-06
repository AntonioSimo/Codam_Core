#include "Serializer.hpp"

int main(void)
{
	Serializer test1;
	Data mydata;

	mydata.myNum = 10;

	std::cout << mydata.myNum << std::endl;

	return (0);
}