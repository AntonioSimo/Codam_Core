#pragma once

#include <algorithm>
#include <iostream>
#include <chrono>
#include <exception>
#include <list>
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

    std::vector<int> _firstContainer; //Attribute
    std::list<int> _secondContainer; //Attribute

    PmergeMe(); //Default Constructor
    ~PmergeMe(); //Destructor

    template <typename T> std::vector<int> fordJohnson(T& container); //Template
    template <typename T> std::vector<std::pair<int, int>> creatingOrderedPairs(T& container); //Template
    void   orderPairs( std::vector<std::pair<int, int>>& pairs); //Static function
    void   binaryInsert(std::vector<int>& sorted, const std::vector<std::pair<int, int>>& pairs, int element); //Static function
    void   recursiveInsert(std::vector<std::pair<int, int>>& pairs, size_t n); //Static function
    void   PmergeMeExe(int argc, char* argv[]); //Static function
    template <typename T> void insertNumber(T& container, int number); //Template
    std::vector<int>    JacobsthalSequence(int containerSize); //Static function

    class PmergeMeException : public std::exception //Exception class
    {
    private:
        std::string message;

    public:
        explicit PmergeMeException(const std::string& msg) : message(msg) {}

        const char* what() const throw() override;
    };
};