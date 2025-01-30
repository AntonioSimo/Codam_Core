#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try 
    {
        PmergeMe pmergeme;
        
        if (argc > 2) 
        {
            throw PmergeMe::PmergeMeException("Error: Too many arguments provided. The expression should be enclosed in double quotes.");
            return (1);
        }
        if (argc < 2) 
        {
            throw PmergeMe::PmergeMeException("Error: Missing expression. Please provide a valid PmergeMe expression enclosed in double quotes.");
            return (1);
        }

        pmergeme.PmergeMeExe(argv[1]);
    } 
    catch (const PmergeMe::PmergeMeException& e) 
    {
        std::cerr << "Error " << e.what() << std::endl;
        return (1);
    }
    return (0);
}