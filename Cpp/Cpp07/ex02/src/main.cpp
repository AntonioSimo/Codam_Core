#include "Array.hpp"

int main(void)
{
	Array<unsigned int> intArray(11);

	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i * 2;
	std::cout << MAGENTA << "This is the intArray size:" << intArray.size() << RESET << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++) 
        std::cout << YELLOW << "intArray[" << i << "] = " << intArray[i] << RESET << std::endl;

	std::cout << std::endl;

	Array<std::string> strArray(3);
	Array<std::string> strArray2;

	strArray2 = strArray;

	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";

	for (unsigned int i = 0; i < strArray.size(); i++) 
        std::cout << YELLOW << "strArray[" << i << "] = " << strArray[i] << RESET << std::endl;

	return (0);
}