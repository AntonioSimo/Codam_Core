#include "RPN.hpp"

int main(int argc, char **argv)
{
    try 
    {
        RPN rpn;
        
        if (argc > 2) 
        {
            throw RPN::RPNException("Error: Too many arguments provided. The expression should be enclosed in double quotes.");
            return (1);
        }
        if (argc < 2) 
        {
            throw RPN::RPNException("Error: Missing expression. Please provide a valid RPN expression enclosed in double quotes.");
            return (1);
        }

        rpn.RpnExe(argv[1]);
        std::cout << rpn.getResult() << std::endl;
    } 
    catch (const RPN::RPNException& e) 
    {
        std::cerr << "Error " << e.what() << std::endl;
        return (1);
    }
    return (0);
}