#include <iostream>

int main()
{
	std::string	 string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string; //Pointer to the string.
	std::string& stringREF = string; //Reference to the string.

	std::cout << &string << std::endl; //Memory address of the string variable.
	std::cout << stringPTR << std::endl; //Memory address held by stringPTR.
	std::cout << &stringREF << std::endl; //The memory address held by stringREF.

	std::cout << string << std::endl; //Value of the string variable.
	std::cout << *stringPTR << std::endl; //Value pointed to by stringPTR.
	std::cout << stringREF << std::endl; //Value pointed to by stringREF.
	return (0);
}