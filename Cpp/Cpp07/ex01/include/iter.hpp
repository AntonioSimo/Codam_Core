#pragma once

#include <iostream>

template <typename T, typename Func> void iter(T *array, int size, Func func)
{
	for (int i = 0; i < size; i++)
		func(array[i]);
}