#pragma once

#include <iostream>

#define GREEN	"\033[32m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

template <typename T, typename Func> void iter(T *array, size_t size, Func func)
{
	if (array == nullptr)
	{
		std::cerr << RED << "Error: Null pointer passed to iter." << RESET << std::endl;
        return;
	}

	for (size_t i = 0; i < size; i++)
		func(array[i]);
}