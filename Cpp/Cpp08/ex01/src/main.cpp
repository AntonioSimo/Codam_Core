#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);

    // sp.addNumber(6);
    // sp.addNumber(2);
    // sp.addNumber(17);
    // sp.addNumber(1);
    // sp.addNumber(11);

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    sp.addNumberRange(numbers.begin(), numbers.end());

    sp.printValue(sp.getContainer());
    //sp.shortestSpan();
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

}