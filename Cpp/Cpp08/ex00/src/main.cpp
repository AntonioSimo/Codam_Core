#include "easyfind.hpp"

int main(void)
{
    // try
    // {
    //     std::vector<int> intArray = {1, 2, 3, 4, 5};

    //     easyfind(intArray, 10);
    // }
    try
    {
        std::vector<int> intArray = {1, 2, 3, 4, 5};

        easyfind(intArray, 3);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}