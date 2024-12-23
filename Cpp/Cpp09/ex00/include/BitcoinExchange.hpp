#pragma once

#include <iostream>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();

    void    BitcoinExe(char* file);

    class BadArgumentException : public std::exception
	{
		public:
            const char* what() const throw() override;
	};
};
