#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form test("Antonio", true, 3, 149);
        Bureaucrat Jack("Jack", 34);
        std::cout << "Form " << test.getName() << " This is the grade to sign: " << test.getGradeToSign() << std::endl;
        std::cout << "This is the grade to Execute: " << test.getGradeToExecute() << std::endl;
        std::cout << "Bureaucrat " << Jack.getName() << test.beSigned(Jack) << std::endl;
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << " first catch" << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << " second catch" << std::endl;
    }
    return (0);
}