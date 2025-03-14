#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << GREEN << "Default PmergeMe constructor called." << RESET << std::endl;
}

PmergeMe::~PmergeMe()
{
    std::cout << RED <<"Destructor PmergeMe called." <<  RESET << std::endl;
}

void    PmergeMe::PmergeMeExe(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        try
        {
            int number = std::stoi(argv[i]);
            if (number <= 0)
                throw PmergeMe::PmergeMeException("Invalid argument.");
            insertNumber(_firstContainer, number);
            insertNumber(_secondContainer, number);
        }
        catch(const PmergeMe::PmergeMeException& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Invalid argument: Not a number." << std::endl;
            return;
        }
         catch (const std::out_of_range& e)
        {
            std::cerr << "Invalid argument: Number out of range." << std::endl;
            return;
        }
    }

    std::cout << "Before: ";
    for (auto i = _firstContainer.begin(); i != _firstContainer.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    Sort(_firstContainer);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "After: ";
    for (auto i = _firstContainer.begin(); i != _firstContainer.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _firstContainer.size() << " elements with std::vector : " << duration.count() * 1000000 << " us" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    Sort(_secondContainer);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time to process a range of " << _secondContainer.size() << " elements with std::list : " << duration.count() * 1000000 << " us" << std::endl;
}

template <typename Container> void PmergeMe::insertNumber(Container& container, int number)
{
    if (std::find(container.begin(), container.end(), number) != container.end()) 
        throw PmergeMe::PmergeMeException("Duplicate found.");
    container.push_back(number);
}

template <typename Container> void PmergeMe::Sort(Container& container)
{
    std::vector<typename Container::value_type> sorted;
    for (auto it = container.begin(); it != container.end(); ++it) 
    {
        typename Container::value_type current = *it;
        auto pos = std::lower_bound(sorted.begin(), sorted.end(), current);
        sorted.insert(pos, current);
    }

    container.clear();
    for (const auto& value : sorted) 
        container.push_back(value);
}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return message.c_str();
}