#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class BitcoinExchange
{
public: //Access specifier
    std::map <std::string, double> bitcoinData; //Attribute

    BitcoinExchange(); //Default Constructor
    BitcoinExchange(const BitcoinExchange& obj); //Copy Constructor
    BitcoinExchange& operator=(const BitcoinExchange& obj); //Copy assignment operator overload
    ~BitcoinExchange(); //Destructor

    void    BitcoinExe(char* file); //Static function
    std::string findNearestDate(const std::string& inputDate); //Static function
    void    calculateValue(const std::string& date, const std::string& value); //Static function
    void    loadExchangeRates(const std::string& file); //Static function
    int     validDate(std::string input); //Static function
    int     validValue(std::string input); //Static function

    class BitcoinExchangeException : public std::exception
    {
    private:
        std::string message;

    public:
        explicit BitcoinExchangeException(const std::string& msg) : message(msg) {}

        const char* what() const throw() override;
    };
};
