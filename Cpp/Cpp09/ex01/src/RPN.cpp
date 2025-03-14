#include "RPN.hpp"

RPN::RPN() : m_result(0)
{
    std::cout << GREEN << "Default RPN constructor called." << RESET << std::endl;
}

RPN::~RPN()
{
    std::cout << RED <<"Destructor RPN called." <<  RESET << std::endl;
}

void RPN::RpnExe(char* expression) 
{
    for (int i = 0; expression[i] != '\0'; ++i) 
	{
        char c = expression[i];

        if (isdigit(c)) 
            operands.push(c - '0');
		else if (c == ADDITION || c == SUBTRACTION || c == MULTIPLICATION || c == DIVISION) 
		{
            if (operands.size() < 2) 
                throw RPNException("There are not enough operands for the operator.");
            performOperation(operands, c);
        } 
		else if (!std::isspace(c))
            throw RPNException("Invalid character in the notation.");
    }
    if (operands.size() != 1) 
        throw RPNException("Syntax error in the expression.");

    m_result = operands.top();
}

void RPN::performOperation(std::stack<int>& operands, char operation) 
{
    int b =  operands.top(); operands.pop();
    int a = operands.top(); operands.pop();
    
    int result;
    switch (operation) 
	{
        case ADDITION: 
			result = a + b; 
			break;
        case SUBTRACTION: 
			result = a - b; 
			break;
        case MULTIPLICATION: 
			result = a * b; 
			break;
        case DIVISION: 
            if (b == 0) 
				throw RPNException("Division by zero!");
            result = a / b; 
            break;
        default:
            throw RPNException("Unknown operator");
    }
    operands.push(result);
}

int RPN::getResult() const 
{
    return (m_result);
}

const char* RPN::RPNException::what() const throw()
{
	return message.c_str();
}