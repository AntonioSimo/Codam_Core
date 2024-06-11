#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form f("Contract", 13, 2);
        Bureaucrat b("Jack", 1);
        std::cout << GREEN << "Form " << f.getName() << " This is the grade to sign: " << f.getGradeToSign() << RESET << std::endl;
        std::cout << YELLOW <<"This is the grade to Execute: " << f.getGradeToExecute() << RESET << std::endl;
        b.signForm(f);
        std::cout << "Bureaucrat " << b.getName() << " is "<< f.getSigned() << " that he can sign the Form."<< std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}