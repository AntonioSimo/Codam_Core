#pragma once

#include <algorithm>
#include <iostream>
#include <chrono>
#include <exception>
#include <stdlib.h>
#include <vector>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class PmergeMe
{
public:

    std::vector<int> _container;

    PmergeMe(); //Default Constructor
    ~PmergeMe(); //Destructor

    void    PmergeMeExe(int argc, char* argv[]);
    void    fordJohnsonSort(std::vector<int>& vec);

    class PmergeMeException : public std::exception
    {
    private:
        std::string message;

    public:
        explicit PmergeMeException(const std::string& msg) : message(msg) {}

        const char* what() const throw() override;
    };
};