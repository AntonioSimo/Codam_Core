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
            if (number < 0)
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
    std::vector<int> sorted_vector = fordJohnson(_firstContainer);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "After: ";
    for (auto i = sorted_vector.begin(); i != sorted_vector.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << sorted_vector.size() << " elements with std::vector : " << duration.count() * 1000000 << " us" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::vector<int> sorted = fordJohnson(_secondContainer);
    std::list<int> sorted_list(sorted.begin(), sorted.end()); 
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time to process a range of " << _secondContainer.size() << " elements with std::list : " << duration.count() * 1000000 << " us" << std::endl;
}

template <typename T> void PmergeMe::insertNumber(T& container, int number)
{
    if (std::find(container.begin(), container.end(), number) != container.end()) 
        throw PmergeMe::PmergeMeException("Duplicate found.");
    container.push_back(number);
}

template <typename T> std::vector<std::pair<int, int>> PmergeMe::creatingOrderedPairs(T& container)
{
    std::vector<std::pair<int, int>> pairs;
    auto it = container.begin();

    while (it != container.end()) 
    {
        auto first = it;
        auto second = std::next(it);

        if (second == container.end())
            break;

        if (*first > *second)
            pairs.emplace_back(*second, *first);
        else
            pairs.emplace_back(*first, *second);

        std::advance(it, 2);
    }

    return (pairs);
}

void PmergeMe::recursiveInsert(std::vector<std::pair<int, int>>& pairs, size_t n) 
{
    if (n == 0)
        return;
    
    recursiveInsert(pairs, n - 1);
    std::pair<int, int> key = pairs[n];
    
    int j = n - 1;

    while (j >= 0 && pairs[j].first > key.first) 
    {
        pairs[j + 1] = pairs[j];
        --j;
    }

    pairs[j + 1] = key;
}

void PmergeMe::orderPairs(std::vector<std::pair<int, int>>& pairs) 
{
    recursiveInsert(pairs, pairs.size() - 1);
    
    for (const auto& p : pairs) 
        std::cout << "[" << p.first << " " << p.second << "]";
    std::cout << std::endl;
}

void PmergeMe::binaryInsert(std::vector<int>& sorted, const std::vector<std::pair<int, int>>& pairs, int element)
{
    auto pos = std::lower_bound(sorted.begin(), sorted.end(), element);
    sorted.insert(pos, element);
}

template <typename T> std::vector<int> PmergeMe::fordJohnson(T& container)
{
    std::vector<std::pair<int, int>> pairs = creatingOrderedPairs(container);
    std::vector<int> sorted;

    orderPairs(pairs);

    for (auto& it : pairs)
        sorted.push_back(it.first);

    for (auto it : pairs)
        binaryInsert(sorted, pairs, it.second);

    if (container.size() % 2 != 0) 
    {
        int lastElement = *(std::prev(container.end()));
        binaryInsert(sorted, pairs, lastElement);
    }

    return (sorted);
}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return (message.c_str());
}