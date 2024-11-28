#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    AForm *form = nullptr;

    // try
    // {
    //     Bureaucrat a("Jack", 73);
    //     Bureaucrat b("Paul", 94);
    //     form = new PresidentialPardonForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    // }
    // try
    // {
    //     Bureaucrat a("Jack", 3);
    //     Bureaucrat b("Paul", 4);
    //     srand(time(0));
    //     form = new RobotomyRequestForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    // }
    // try
    // {
    //     Bureaucrat a("Jack", 3);
    //     Bureaucrat b("Paul", 56);
    //     form = new ShrubberyCreationForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    // }
    try
    {
        Bureaucrat a("Jack", 3);
        Bureaucrat b("Paul", 56);
        Intern intern;

        form = intern.makeForm("ShrubberyCreationForm", "Tom");
        form->beSigned(a);
        form->execute(b);

    }    
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    if (form)
        delete(form);
    return (0);
}