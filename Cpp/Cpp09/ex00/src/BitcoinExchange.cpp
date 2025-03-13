#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << GREEN << "Default BitcoinExchange constructor called." << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    std::cout << "Copy BitcoinExchange constructor called." << std::endl;

   *this = obj;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (this != &obj)
        *this = obj;

   std::cout << "Copy BitcoinExchange assignment operator called." << std::endl;

   return (*this);
}
BitcoinExchange::~BitcoinExchange()
{
    std::cout << RED <<"Destructor BitcoinExchange called." <<  RESET << std::endl;
}

std::string deleteSpace(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");

    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }

    return str.substr(first, last - first + 1);
}

void BitcoinExchange::loadExchangeRates(const std::string& file)
{
    std::ifstream myFile(file);
    if (myFile.fail()) 
        throw BitcoinExchange::BitcoinExchangeException("could not open file.");

    std::string line;
    std::getline(myFile, line);
    if (line != "date,exchange_rate")
    {
        throw BitcoinExchange::BitcoinExchangeException("invalid file.");
    }
    while (std::getline(myFile, line))
    {
        try
        {
            std::stringstream ss(line);
            std::string date;
            std::string rateStr;

            if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
                continue;
            
            if (validDate(date) == 1)
                return;
            if (validValue(rateStr) == 1)
                return;
            double rate = std::stod(rateStr);
            bitcoinData[date] = rate;
        }
        catch (const BitcoinExchange::BitcoinExchangeException& e)
		{
            std::cerr << RED << "Error inside the database: " << e.what() << RESET << std::endl;
            continue;
		}
    }
    if (bitcoinData.size() == 0)
        throw BitcoinExchange::BitcoinExchangeException("Error: the file is empty.");
    myFile.close();
}

int BitcoinExchange::validDate(std::string input)
{
    try
    {
        for (size_t i = 0; i < input.size(); i++)
        {
            if (input[i] == '-' || input[i] == '.')
                i++;
            if (!isdigit(input[i]))
            {
                std::cerr << "Error: bad input => " << input << std::endl;
                return (1);
            }
        }       
        int year = std::stoi(input.substr(0, 4));
        int month = std::stoi(input.substr(5, 2));
        int day = std::stoi(input.substr(8, 2));
        if (year < 2009)
        {
            std::cerr << "Error: bad input => " << input << std::endl;
            return (1);
        }
        if (month < 1 || month > 12)
        {
            std::cerr << "Error: bad input => " << input << std::endl;
            return (1);
        }   
        if (day < 1 || day > 31)
        {
            std::cerr << "Error: bad input => " << input << std::endl;
            return (1);
        }
        if (input.size() != 10 || input[4] != '-' || input[7] != '-')
        {
            throw BitcoinExchange::BitcoinExchangeException(("Invalid date inside the file."));
            return (1);
        }
    }
    catch(const BitcoinExchange::BitcoinExchangeException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

int	BitcoinExchange::validValue(std::string input)
{
    try
    {
    	if (input.empty())
        {
            throw BitcoinExchange::BitcoinExchangeException(("Invalid value inside the file."));
            return (1);
        }
        if (input[0] == '-')
            throw BitcoinExchange::BitcoinExchangeException("Error: not a positive number.");
        for (size_t i = 0; i < input.size(); i++)
        {
            if (input[i] == '.')
                i++;
            if (!isdigit(input[i]))
            {
                std::cerr << "Error: bad input => " << input << std::endl;
                return (1);
            }
        }     
    }
    catch(const BitcoinExchange::BitcoinExchangeException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

std::string BitcoinExchange::findNearestDate(const std::string& inputDate)
{
    if (bitcoinData.find(inputDate) != bitcoinData.end())
        return inputDate;

    auto closestDate = bitcoinData.lower_bound(inputDate);
    closestDate--;
    return (closestDate->first);
}

void BitcoinExchange::calculateValue(const std::string& date, const std::string& value)
{
    if (validDate(date) == 1)
        return;
    if (validValue(value) == 1)
        return;
    std::string nearestDate = findNearestDate(date);
    double nearestValue = bitcoinData[nearestDate];

    try 
    {
        double bitcoinValue = std::stod(value);
        if (bitcoinValue < 0)
        {
            return;
        }
        if (bitcoinValue > 1000) 
        {
            std::cerr << "Error: too large a number" << std::endl;
            return ;
        }
        double finalValue = bitcoinValue * nearestValue;
        std::cerr << date << " => " << bitcoinValue << " = " << finalValue << std::endl;
    }
    catch (const std::invalid_argument& e) 
    {
        return;
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Error: number out of range" << std::endl;
    }
}

void BitcoinExchange::BitcoinExe( char* file)
{
	loadExchangeRates("./data.csv");

	std::ifstream myFile(file);
	if (!myFile.is_open())
		throw BitcoinExchange::BitcoinExchangeException("could not open file.");

	std::string line;
	std::getline(myFile, line);
    if (line != "date | value")
    {
        throw BitcoinExchange::BitcoinExchangeException("invalid file.");
    }

	while (std::getline(myFile, line))
	{
	    try
	    {
	        std::stringstream ss(line);
	        std::string date;
	        std::string value;

        	if (!std::getline(ss, date, '|') || !std::getline(ss, value))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            date = deleteSpace(date);
            value = deleteSpace(value);

			calculateValue(date, value);
		}
    	catch (const BitcoinExchange::BitcoinExchangeException& e)
    	{
    		std::cerr << RED <<  e.what() << RESET << std::endl;
    	}
	}
	myFile.close();
}

const char* BitcoinExchange::BitcoinExchangeException::what() const throw()
{
	return message.c_str();
}
