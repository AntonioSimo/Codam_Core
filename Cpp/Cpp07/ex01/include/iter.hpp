#pragma once

#include <iostream>

template <typename T, typename Func> void iter(T *array, size_t size, Func func)
{
	if (array == nullptr)
	{
		std::cerr << "Error: Null pointer passed to iter." << std::endl;
        return;
	}

	for (size_t i = 0; i < size; i++)
		func(array[i]);
}