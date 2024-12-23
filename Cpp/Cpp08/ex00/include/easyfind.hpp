#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

template <typename T>

void easyfind(T container, int value)
{
    auto occurence = std::find(container.begin(), container.end(), value);

    if (occurence != container.end()) 
        std::cout << GREEN << "Value " << value << " found in container." << RESET << std::endl;
    else 
        throw std::invalid_argument("Value not found in container.");
}