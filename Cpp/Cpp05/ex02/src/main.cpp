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
        Bureaucrat c("Andrew", 24);
        Bureaucrat d("Tom", 6);
        // ShrubberyCreationForm test("test");
        //AForm* test1  = new ShrubberyCreationForm("test1");
        //AForm* test2 = new RobotomyRequestForm("test2");
        srand(time(0));
        AForm* test3 = new PresidentialPardonForm("test3");
        // ShrubberyCreationForm("test");
        //test1->beSigned(c);
        //test1->execute(d);
        //test2->beSigned(c);
        //test2->execute(d);
        
         test3->beSigned(c);
         test3->execute(d);
        // std::cout << GREEN << "Form " << f.getName() << " This is the grade to sign: " << f.getGradeToSign() << RESET << std::endl;
        // std::cout << YELLOW <<"This is the grade to Execute: " << f.getGradeToExecute() << RESET << std::endl;
        // b.signForm(f);
        // f.beSigned(b);
        // std::cout << "Bureaucrat " << b.getName() << " is "<< f.getSigned() << " that he can sign the Form."<< std::endl;
        // delete test1;
        delete test3;
        // delete test3;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}