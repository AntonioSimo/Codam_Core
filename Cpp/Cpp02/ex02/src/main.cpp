#include "Fixed.hpp"

int main(void)
{
    Fixed   a(10.0f);
    Fixed   b(8.0f);

    //comparison operators
    std::cout << "Comparison operators" << std::endl;
    std::cout << (b > a) << std::endl;
    std::cout << (b < a) << std::endl;
    std::cout << (b <= a) << std::endl;
    std::cout << (b >= a) << std::endl;
    std::cout << (b == a) << std::endl;
    std::cout << (b != a) << std::endl;
    std::cout << std::endl;

    //arithmetic operators
    std::cout << "Arithmetic operators" << std::endl;
    std::cout << (b + a) << std::endl;
    std::cout << (b - a) << std::endl;
    std::cout << (b * a) << std::endl;
    std::cout << (b / a) << std::endl;
    std::cout << std::endl;

    //increment operators
    std::cout << "Increment operators" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl;

    //decrement operators
    std::cout << "Decrement operators" << std::endl;
    std::cout << b << std::endl;
    std::cout << --b << std::endl;
    std::cout << b << std::endl;
    std::cout << b-- << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;

    std::cout << "Find the smallest number" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << std::endl;

    std::cout << "Find the gratest number" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << std::endl;
}