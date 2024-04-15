#include <iostream>

# define CYAN "\033[36m"
# define GREEN  "\033[32m"
# define MAGENTA "\033[35m"
# define RED  "\033[31m"
# define YELLOW  "\033[33m"
# define RESET  "\033[0m"

int main(void)
{
	std::string	 string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string; //Pointer to the string.
	std::string& stringREF = string; //Reference to the string.

	std::cout << CYAN << &string << RESET << std::endl; //Memory address of the string variable.
	std::cout << GREEN << stringPTR << RESET << std::endl; //Memory address held by stringPTR.
	std::cout << MAGENTA << &stringREF << RESET << std::endl; //The memory address held by stringREF.

	std::cout << RED << string << RESET << std::endl; //Value of the string variable.
	std::cout << YELLOW << *stringPTR << RESET << std::endl; //Value pointed to by stringPTR.
	std::cout << stringREF << std::endl; //Value pointed to by stringREF.
	return (0);
}