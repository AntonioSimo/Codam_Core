#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("Jack", 3);
        Bureaucrat b("Paul", 56);
        Bureaucrat c("Andrew", 140);
        Bureaucrat d("Tom", 14);
        ShrubberyCreationForm test("test");

        AForm* test1 = &test;
        test.execute();
        // std::cout << GREEN << "Form " << f.getName() << " This is the grade to sign: " << f.getGradeToSign() << RESET << std::endl;
        // std::cout << YELLOW <<"This is the grade to Execute: " << f.getGradeToExecute() << RESET << std::endl;
        // b.signForm(f);
        // f.beSigned(b);
        // std::cout << "Bureaucrat " << b.getName() << " is "<< f.getSigned() << " that he can sign the Form."<< std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}