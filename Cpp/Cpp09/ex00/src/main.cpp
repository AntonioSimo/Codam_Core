#include "../include/BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    (void) argv;
    try
    {
        if (argc == 2)
        {
            BitcoinExchange Bitcoin;
            Bitcoin.BitcoinExe(argv[1]);
        }
        else
            throw BitcoinExchange::BadArgumentException();
    }
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
