#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class BitcoinExchange
{
public: //Access specifier
    std::unordered_map <std::string, double> bitcoinData; //Attribute

    BitcoinExchange(); //Default Constructor
    BitcoinExchange(const BitcoinExchange& obj); //Copy Constructor
    BitcoinExchange& operator=(const BitcoinExchange& obj); //Copy assignment operator overload
    ~BitcoinExchange(); //Destructor

    void    BitcoinExe(char* file); //Static function
    void    calculateValue(const std::string& date, const std::string& value); //Static function
    void    loadExchangeRates(const std::string& file); //Static function
    void	validDate(std::string input); //Static function
    void	validValue(std::string input); //Static function

    class BadArgumentException : public std::exception //Bad argument exception
	{
		public: //Access specifier
            const char* what() const throw() override;
	};

    class invalidDateException : public std::exception //Invalid data exception
    {
    	public: //Access specifier
            const char* what() const throw() override;
    };

     class invalidBitcoinValueException : public std::exception //Invalid Bitcoin value exception
    {
    	public: //Access specifier
            const char* what() const throw() override;
    };
};
