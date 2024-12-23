#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << GREEN << "Default BitcoinExchange constructor called." << RESET << std::endl;
}
BitcoinExchange::~BitcoinExchange()
{
    std::cout << RED <<"Destructor BitcoinExchange called." <<  RESET << std::endl;
}

 void    BitcoinExchange::BitcoinExe(char* file)
 {
    std::cout << file << std::endl;
 }

const char* BitcoinExchange::BadArgumentException::what() const throw()
{
	return ("Error: could not open file.");
}