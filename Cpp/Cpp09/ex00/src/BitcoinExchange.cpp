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

void BitcoinExchange::loadExchangeRates(const std::string& file)
{
    std::ifstream myFile(file);
    if (!myFile.is_open())
        throw BitcoinExchange::BadArgumentException();

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

    myFile.close();
}

void	BitcoinExchange::validDate(std::string input)
{
    if (input.size() != 10 || input[4] != '-' || input[7] != '-')
        throw BitcoinExchange::invalidDateException();
}

void	BitcoinExchange::validValue(std::string input)
{
	if (input.empty() || input[0] == '-')
		throw BitcoinExchange::invalidBitcoinValueException();
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]) && input[i] != '.')
			throw BitcoinExchange::invalidBitcoinValueException();
	}
    double value = std::stod(input);

    if (value < 0 || value > 100000)
        throw BitcoinExchange::invalidBitcoinValueException();
}

void BitcoinExchange::calculateValue(const std::string& date, const std::string& value)
{
    // Verifica che la data sia presente nel database dei tassi di cambio
    auto it = bitcoinData.find(date);
    if (it == bitcoinData.end())
    {
        throw BitcoinExchange::invalidDateException(); // Lancia un'eccezione se la data non esiste
    }

    // Converti il valore del Bitcoin in double
    double bitcoinValue = std::stod(value);
    double exchangeRate = it->second;

    // Calcola il valore moltiplicato per il tasso di cambio
    double result = bitcoinValue * exchangeRate;

    // Stampa il risultato
    std::cout << date << " => " << bitcoinValue << " | " << exchangeRate << " = " << result << std::endl;
}

void BitcoinExchange::BitcoinExe( char* file)
{
	loadExchangeRates("../cpp_09/data.csv");

	std::ifstream myFile(file);
	if (!myFile.is_open())
		throw BitcoinExchange::BadArgumentException();

	std::string line;

	std::getline(myFile, line);
    std::stringstream headerStream(line);
    std::string headerDate, headerExchangeRate;
    std::getline(headerStream, headerDate, ',');
    std::getline(headerStream, headerExchangeRate, ',');

    if (headerDate != "date" || headerExchangeRate != "exchange_rate")
        throw BitcoinExchange::BadArgumentException();

	try
	{
		while (std::getline(myFile, line))
		{
	        std::stringstream ss(line);
	        std::string date;
	        std::string value;

        	if (!std::getline(ss, date, ',') || !std::getline(ss, value, ','))
        	    throw BitcoinExchange::BadArgumentException();

			validDate(date);
			validValue(value);

			calculateValue(date, value);
		}
	}
	catch (const BitcoinExchange::invalidDateException& e)
	{
		std::cerr << RED <<  e.what() << RESET << std::endl;
	}
	catch (const BitcoinExchange::invalidBitcoinValueException& e)
	{
		std::cerr << RED <<  e.what() << RESET << std::endl;
	}
	myFile.close();

	std::cout << "date | value" << std::endl;
	for (const auto& entry : bitcoinData)
	{
		std::cout << entry.first << " | " << entry.second << std::endl;
	}
}

const char* BitcoinExchange::BadArgumentException::what() const throw()
{
	return ("Error: could not open file.");
}

const char* BitcoinExchange::invalidDateException::what() const throw()
{
	return ("Error: Invalid date inside the file.");
}

const char* BitcoinExchange::invalidBitcoinValueException::what() const throw()
{
	return ("Error: Invalid Bitcoin value inside the file.");
}