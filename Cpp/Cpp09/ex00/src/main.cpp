#include "../include/BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    try
    {
        if (argc == 2)
        {
            BitcoinExchange Bitcoin;
            Bitcoin.BitcoinExe(argv[1]);
        }
        else
            throw BitcoinExchange::BitcoinExchangeException("Error: could not open file.");
    }
    catch (const BitcoinExchange::BitcoinExchangeException& e) 
    {
        std::cerr << RED << "Error " << e.what() << RESET << std::endl;
        return (1);
    }
}
