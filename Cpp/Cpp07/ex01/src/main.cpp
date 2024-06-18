#include <iter.hpp>

void	printInt(int const &x)
{
	std::cout << x << " ";
}

void	printString(std::string const &str)
{
	std::cout << str << " ";
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5, 6,};
	std::string strArray[] = {"Hello", "World!", "This", "is", "my", "second", "Template."};

	std:: cout << "Int array: ";
	::iter(intArray, 6, printInt);
	std::cout << std::endl;

	std::cout << "Str array: ";
	::iter(strArray, 7, printString);
	std::cout << std::endl;

	return (0);
}