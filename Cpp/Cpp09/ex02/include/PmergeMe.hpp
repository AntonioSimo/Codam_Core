#pragma once

#include <algorithm>
#include <chrono>
#include <deque>
#include <exception>
#include <iostream>
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

    std::vector<int> _vector; //Attribute
    std::deque<int> _deque; //Attribute //DA MODIFICARE IN DEQUE

    PmergeMe(); //Default Constructor
    PmergeMe(const PmergeMe& obj); //Copy Constructor
    PmergeMe& operator=(const PmergeMe& obj); //Copy assignment operator overload
    ~PmergeMe(); //Destructor

    template <typename T, typename P> T fordJohnson(T& container, P& pair_container); //Template
    template <typename T, typename P> P creatingOrderedPairs(T& container, P& pair_container); //Template
    template <typename P> void orderPairs(P& pairs) ; //Static function
    template <typename T, typename P> size_t  binaryInsert(T& sorted, P& pairs, int element); //Static function
    template <typename P> void recursiveInsert(P& pairs, size_t pairSize); //Static function
    void    PmergeMeExe(int argc, char* argv[]); //Static function
    void    insertNumber(int number); //Template
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