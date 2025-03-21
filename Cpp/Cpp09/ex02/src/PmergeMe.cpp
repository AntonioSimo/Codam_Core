#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << GREEN << "Default PmergeMe constructor called." << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    std::cout << "Copy PmergeMe constructor called." << std::endl;

   *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if (this != &obj)
        *this = obj;

   std::cout << "Copy PmergeMe assignment operator called." << std::endl;

   return (*this);
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
            insertNumber(number);
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

    std::cout << "Before Vector: ";
    for (auto i = _vector.begin(); i != _vector.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "Before Deque: ";
    for (auto i = _deque.begin(); i != _deque.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::pair<int, int>> vecotr_pair;
    std::vector<int> sorted_vector = fordJohnson(_vector, vecotr_pair);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "After Vector: ";
    for (auto i = sorted_vector.begin(); i != sorted_vector.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::deque<std::pair<int, int>> deque_pair;
    std::deque<int> sorted_deque = fordJohnson(_deque, deque_pair);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "After Deque: ";
    for (auto i = sorted_vector.begin(); i != sorted_vector.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << sorted_vector.size() << " elements with std::vector : " << duration.count() * 1000000 << " us" << std::endl;
    std::cout << "Time to process a range of " << sorted_deque.size() << " elements with std::list : " << duration.count() * 1000000 << " us" << std::endl;
}

void PmergeMe::insertNumber(int number)
{
    if (std::find(_vector.begin(), _vector.end(), number) != _vector.end() || std::find(_deque.begin(), _deque.end(), number) != _deque.end()) 
        throw PmergeMe::PmergeMeException("Duplicate found.");
    _vector.push_back(number);
    _deque.push_back(number);
}

template <typename T, typename P> P PmergeMe::creatingOrderedPairs(T& container, P& pair_container)
{
    auto it = container.begin();

    while (it != container.end()) 
    {
        auto first = it;
        auto second = std::next(it);

        if (second == container.end())
            break;

        if (*first > *second)
            pair_container.emplace_back(std::make_pair(*second, *first));
        else
            pair_container.emplace_back(std::make_pair(*first, *second));

        std::advance(it, 2);
    }

    return (pair_container);
}

std::vector<int>    PmergeMe::JacobsthalSequence(int containerSize)
{
    std::vector<int> sequence = {0, 1};

    for (int i = 2; i < containerSize; i++)
        sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);

    return (sequence);
}

template <typename P> void PmergeMe::recursiveInsert(P& pairs, size_t pairSize) 
{
    if (pairSize == 0)
        return;
    
    recursiveInsert(pairs, pairSize - 1);
    std::pair<int, int> key = pairs[pairSize];
    
    int j = pairSize - 1;

    while (j >= 0 && pairs[j].first > key.first) 
    {
        pairs[j + 1] = pairs[j];
        --j;
    }

    pairs[j + 1] = key;
}

template <typename P> void PmergeMe::orderPairs(P& pairs) 
{
    recursiveInsert(pairs, pairs.size() - 1);
}

template <typename T, typename P> size_t  PmergeMe::binaryInsert(T& sorted, P& pairs, int element)
{
    std::vector<int> temp_vec = this->JacobsthalSequence(pairs.size());

    size_t i = sorted.size() - 1;
    int e = 0;
    while (i >= temp_vec[e])
    {
        if (element >= sorted[i])
        {
            return i + 1;
        }
        else
        {
            while (i >= 0)
            {
                if (element >= sorted[i])
                    break ;
                i--;
            }
            return i + 1;
        }
        e++;
    }
    
    return (i);
}

template <typename T, typename P> T PmergeMe::fordJohnson(T& container, P& pair_container)
{
    pair_container = creatingOrderedPairs(container, pair_container);
    T sorted;

    orderPairs(pair_container);

    for (auto& it : pair_container)
        sorted.push_back(it.first);

    auto it = pair_container.begin();
    for (; it != pair_container.end(); it++)
    {
        size_t pos = binaryInsert(sorted, pair_container, it->second);
        sorted.insert(sorted.begin() + pos, it->second);
    }

    if (container.size() % 2 != 0) 
    {
        int lastElement = *(std::prev(container.end()));
        auto pos = std::lower_bound(sorted.begin(), sorted.end(), lastElement);
        sorted.insert(pos, lastElement);;
    }

    return (sorted);
}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return (message.c_str());
}