#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        AForm f("Antonio", true, 13, 2);
        Bureaucrat b("Jack", 15);
        std::cout << GREEN << "Form " << f.getName() << " This is the grade to sign: " << f.getGradeToSign() << RESET << std::endl;
        std::cout << YELLOW <<"This is the grade to Execute: " << f.getGradeToExecute() << RESET << std::endl;
        b.signForm(f);
        f.beSigned(b);
        std::cout << "Bureaucrat " << b.getName() << " is "<< f.getSigned() << " that he can sign the Form."<< std::endl;
    }
    catch(const AForm::GradeTooHighException& e)
    {
        std::cerr << e.what() << " first catch" << std::endl;
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << " second catch" << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << " first catch" << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << " second catch" << std::endl;
    }
    return (0);
}