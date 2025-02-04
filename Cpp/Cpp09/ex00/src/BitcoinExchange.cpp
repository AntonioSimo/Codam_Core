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
        throw BitcoinExchange::BitcoinExchangeException("Error: could not open file.");

    std::string line;
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr, ','))
            continue;

        try
        {
            double rate = std::stod(rateStr);
            bitcoinData[date] = rate;
        }
        catch (const std::invalid_argument& e)
		{
            continue;
		}
    }
    if (bitcoinData.size() == 0)
        throw BitcoinExchange::BitcoinExchangeException("Error: the file is empty.");;
    myFile.close();
}

void	BitcoinExchange::validDate(std::string input)
{
    if (input.size() != 10 || input[4] != '-' || input[7] != '-')
        // throw BitcoinExchange::invalidDateException();
        std::cout << "Ciao!" << std::endl;
}

void	BitcoinExchange::validValue(std::string input)
{
	if (input.empty())
    {
        return;
    }
    if (input[0] == '-')
    {
        return;
    }
	// for (size_t i = 0; i < input.size(); i++)
	// {
	// 	if (!std::isdigit(input[i]) && input[i] != '.')
	// 		throw BitcoinExchange::invalidBitcoinValueException();
	// }
}

std::string BitcoinExchange::findNearestDate(const std::string& inputDate)
{
    if (bitcoinData.find(inputDate) != bitcoinData.end())
        return inputDate;

    std::string closestDate;
    double minDifference = std::numeric_limits<double>::max();

    for (const auto& entry : bitcoinData)
    {
        if (inputDate.size() >= 10 && entry.first.size() >= 10)
        {
            double diff = std::abs(std::stod(inputDate.substr(0, 4) + inputDate.substr(5, 2) + inputDate.substr(8, 2)) -
                                   std::stod(entry.first.substr(0, 4) + entry.first.substr(5, 2) + entry.first.substr(8, 2)));

            if (diff < minDifference)
            {
                minDifference = diff;
                closestDate = entry.first;
            }
        }
        // else
        //     throw BitcoinExchange::invalidDateException();
    }
    return closestDate;
}

void BitcoinExchange::calculateValue(const std::string& date, const std::string& value)
{
    std::string nearestDate = findNearestDate(date);
    double nearestValue = bitcoinData[nearestDate];

    try {
        double bitcoinValue = std::stod(value);
        if (bitcoinValue < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
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
		throw BitcoinExchange::BitcoinExchangeException("Error: could not open file.");

	std::string line;
	std::getline(myFile, line);
    std::cout << line << std::endl;
    std::stringstream headerStream(line);
    std::string headerDate, headerExchangeRate;
    std::getline(headerStream, headerDate, '|');
    std::getline(headerStream, headerExchangeRate);
    headerDate = deleteSpace(headerDate);
    headerExchangeRate = deleteSpace(headerExchangeRate);

	while (std::getline(myFile, line))
	{
	    try
	    {
	        std::stringstream ss(line);
	        std::string date;
	        std::string value;

        	if (!std::getline(ss, date, '|') || !std::getline(ss, value, '|'))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
            }

            date = deleteSpace(date);
            value = deleteSpace(value);
			validDate(date);
			validValue(value);

			calculateValue(date, value);
		}
    	// catch (const BitcoinExchange::invalidDateException& e)
    	// {
    	// 	std::cerr << RED <<  e.what() << RESET << std::endl;
    	// }
    	catch (const BitcoinExchange::BitcoinExchangeException& e)
    	{
    		std::cerr << RED <<  e.what() << RESET << std::endl;
    	}
	}
	myFile.close();
}

// const char* BitcoinExchange::BadArgumentException::what() const throw()
// {
// 	return ("Error: could not open file.");
// }

// const char* BitcoinExchange::invalidDateException::what() const throw()
// {
// 	return ("Error: Invalid date inside the file.");
// }

// const char* BitcoinExchange::invalidBitcoinValueException::what() const throw()
// {
// 	return ("Error: Invalid Bitcoin value inside the file.");
// }

const char* BitcoinExchange::BitcoinExchangeException::what() const throw()
{
	return message.c_str();
}
