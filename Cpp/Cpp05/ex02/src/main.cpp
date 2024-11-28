#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    AForm *form = nullptr;

    try
    {
        Bureaucrat a("Jack", 25);
        Bureaucrat b("Paul", 4);
        AForm *form = new PresidentialPardonForm("Paul");

        form->beSigned(a);
        form->execute(b);
    }
    // try
    // {
    //     Bureaucrat a("Jack", 72);
    //     Bureaucrat b("Paul", 44);
    //     srand(time(0));
    //     AForm *form = new RobotomyRequestForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    // }
    // try
    // {
    //     Bureaucrat a("Jack", 145);
    //     Bureaucrat b("Paul", 136);
    //     form = new ShrubberyCreationForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    // }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    if(form)
        delete(form);
    return (0);
}