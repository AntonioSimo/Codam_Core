#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try 
    {
        PmergeMe pmergeme;
        
        if (argc < 2) 
        {
            throw PmergeMe::PmergeMeException("Missing expression. Please provide a valid PmergeMe expression enclosed in double quotes.");
            return (1);
        }
        
        pmergeme.PmergeMeExe(argc, argv);
    } 
    catch (const PmergeMe::PmergeMeException& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}