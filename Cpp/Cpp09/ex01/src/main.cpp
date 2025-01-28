#include "RPN.hpp"

int main(int argc, char **argv)
{
	    try
    {
        if (argc == 2)
        {
            RPN Rpn;

            Rpn.RpnExe(argv[1]);
        }
        else
            throw RPN::RPNException("Error: The argument is out of the valid range. You should include the argument inside the double quotes.");
    }
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}