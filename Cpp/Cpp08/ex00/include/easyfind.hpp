#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>

void easyfind(T container, int value)
{
    auto occurence = std::find(container.begin(), container.end(), value);

    if (occurence != container.end()) 
        std::cout << "Value " << value << " found in container." << std::endl;
    else 
        throw std::invalid_argument("Value not found in container.");
}