#include "RPN.hpp"

RPN::RPN() : m_result(0)
{
    std::cout << GREEN << "Default RPN constructor called." << RESET << std::endl;
}

RPN::~RPN()
{
    std::cout << RED <<"Destructor RPN called." <<  RESET << std::endl;
}

//void	RPN::makeOtherOperation(std::queue<int> data)
//{
//	int other_result = 0;

//	for (; !data.empty();)
//	{
//		if (data.back() == 43)
//		{
//			other_result = m_result + data.front();
//			data.pop();
//		}
//		if (data.front() == 43 && data.size() == 1)
//			data.pop();
//	}
//	std::cout << other_result << std::endl;
//}

//void	RPN::makeOperation()
//{
//	int number = 0;


//	if (data.empty())
//		throw RPN::RPNException("Error: the container is empty.");
//	else 
//	{
//		for (; !data.empty();)
//		{
//			number = data.front();
//			//std::cout << number << std::endl;
//			if (data.back() == 43)
//			{
//				data.pop();
//				//std::cout << "This is number: " << number << std::endl;
//				//std::cout << "This is the data.front: " << data.front() << std::endl;
//				m_result = number + data.front();
//				break;
//			}
//			if (data.back() == 42)
//			{
//				data.pop();
//				m_result = number * data.front();
//			}
//			else 
//				m_result = 0;
//		}
//		std::cout << m_result << std::endl;
//		data.pop();
//		if (data.size() == 1)
//			return ;
//		for (; !data.empty();)
//		{
//			if (data.front() == 43)
//			{
//				data.pop();
//			}
//			makeOtherOperation(data);
//			break;
//		}
//	}
//}

void	RPN::makeOperation()
{
	for (; !operationVector.empty();)
	{
  		{
  			std::cout << operationVector.front() << " ";
  			operationVector.pop();
  		}
  			std::cout << std::endl;
	}

	for (; !math_operator.empty();)
	{
  		{
  			std::cout << math_operator.front() << " ";
  			math_operator.pop();
  		}
  			std::cout << std::endl;
	}
}

void	RPN::RpnExe(char* argv)
{
	int i = 0;
	size_t number = 0;

	while (argv[i])
	{
		if (isdigit(argv[i]))
		{
			number = argv[i] - '0';
			operationVector.push(number);
			i++;
		}
		else if (isspace(argv[i]) && !isdigit(argv[i - 2]))
			i++;
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
		{
			math_operator.push(argv[i]);
			i++;
		}	
		else
			throw RPN::RPNException("Error: the only arguments can be number or math operators");
	}

	makeOperation();
}

//const char* RPN::RPNException::what() const throw()
//{
//	return ("Error: The following numbers, to apply the mathematical notation, should be less than 10.");
//}

const char* RPN::RPNException::what() const throw()
{
	return message.c_str();
}