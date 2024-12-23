#pragma once

#include <iostream>

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

template <typename  T> 

void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T> T min(T x, T y)
{
	return (x < y) ? x : y;
}

template <typename T> T max(T x, T y)
{
	return (x > y) ? x : y;
}