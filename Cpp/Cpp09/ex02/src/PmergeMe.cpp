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

template <typename Container> void PmergeMe::insertNumber(Container& container, int number)
{
    if (std::find(container.begin(), container.end(), number) != container.end()) 
        throw PmergeMe::PmergeMeException("Duplicate found.");
    container.push_back(number);
}

template <typename Container>   std::vector<std::pair<typename Container::value_type, typename Container::value_type>> PmergeMe::creatingOrderedPairs(Container& container)
{
    std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairs;
    auto it = container.begin();

    while (it != container.end()) {
        auto first = it;
        auto second = std::next(it);

        if (second == container.end()) // Se c'è un numero dispari, saltiamo l'ultimo elemento per ora
            break;

        if (*first > *second)
            pairs.emplace_back(*second, *first);
        else
            pairs.emplace_back(*first, *second);

        std::advance(it, 2); // Passiamo alla coppia successiva
    }

    return pairs;
}

std::vector<int>    PmergeMe::JacobsthalSequence(int containerSize)
{
    std::vector<int> sequence = {0, 1};

    for (int i = 2; i < containerSize; i++)
        sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);

    return (sequence);
}

void binaryInsert(std::vector<int>& sorted, int element) 
{
    auto pos = std::lower_bound(sorted.begin(), sorted.end(), element);
    sorted.insert(pos, element);
}

template <typename Container> 
const std::vector<typename Container::value_type> PmergeMe::fordJohnson(Container& container)
{
    std::vector<std::pair<typename Container::value_type, typename Container::value_type>> pairs = creatingOrderedPairs(container);
    std::vector<typename Container::value_type> sorted;

    if (!pairs.empty())
        sorted.push_back(pairs[0].second);  // Inseriamo il più grande della prima coppia

    std::vector<int> jacobsthalIndices = JacobsthalSequence(pairs.size());

    for (int index : jacobsthalIndices) {
        if (index < pairs.size()) {
            binaryInsert(sorted, pairs[index].first);
            binaryInsert(sorted, pairs[index].second);
        }
    }

    // Se il numero di elementi è dispari, inseriamo l'ultimo numero rimasto
    if (container.size() % 2 != 0) {
        int lastElement = *(std::prev(container.end()));  // Ultimo elemento non accoppiato
        binaryInsert(sorted, lastElement);
    }

    return sorted;
}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return message.c_str();
}