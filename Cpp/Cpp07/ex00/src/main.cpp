#include "whatever.hpp"

int main(void)
{
	int a = 15;
	int b = 10;

	::swap(a, b);
	std::cout << GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << YELLOW << "min( a, b ) = " << ::min( a, b ) << RESET << std::endl;
	std::cout << CYAN << "max( a, b ) = " << ::max( a, b ) << RESET << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << GREEN << "c = " << c << ", d = " << d << RESET <<std::endl;
	std::cout << YELLOW << "min( c, d ) = " << ::min( c, d ) << RESET << std::endl;
	std::cout << CYAN << "max( c, d ) = " << ::max( c, d ) << RESET << std::endl;
	
	return(0);
}