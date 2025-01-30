#pragma once

#include <iostream>
#include <exception>
#include <stack>
#include <stdlib.h>
#include <vector>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

class RPN
{
public:
    std::stack<int> operands; //Attribute
    int m_result; //Attribute

    RPN(); //Default Constructor
    ~RPN(); //Destructor

    void    RpnExe(char* expression);
    void    performOperation(std::stack<int>& operands, char operation);
    int     getResult() const;

    class RPNException : public std::exception
    {
    private:
        std::string message;

    public:
        explicit RPNException(const std::string& msg) : message(msg) {}

        const char* what() const throw() override;
    };
};