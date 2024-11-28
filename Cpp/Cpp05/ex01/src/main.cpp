#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form f("Contract", 13, 2);
        Bureaucrat b("Jack", 14);

        std::cout << GREEN << b << RESET;
        f.beSigned(b);
        b.signForm(f);
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}