#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    // try
    // {
    //     Bureaucrat a("Jack", 73);
    //     Bureaucrat b("Paul", 94);
    //     AForm *form = new PresidentialPardonForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    //     delete (form);
    // }
    // try
    // {
    //     Bureaucrat a("Jack", 3);
    //     Bureaucrat b("Paul", 4);
    //     srand(time(0));
    //     AForm *form = new RobotomyRequestForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    //     delete (form);
    // }
    // try
    // {
    //     Bureaucrat a("Jack", 3);
    //     Bureaucrat b("Paul", 56);
    //     AForm *form = new ShrubberyCreationForm("Paul");

    //     form->beSigned(a);
    //     form->execute(b);
    //     delete (form);
    // }
    try
    {
        Bureaucrat a("Jack", 3);
        Bureaucrat b("Paul", 56);
        Intern intern;
        AForm *form;

        form = intern.makeForm("ShrubberyCreationForm", "Tom");
        form->beSigned(a);
        form->execute(b);
        delete (form);
    }    
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}