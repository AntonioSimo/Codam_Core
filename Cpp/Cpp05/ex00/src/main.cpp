#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat Bureaucrat("Antonio", 149);
        std::cout << Bureaucrat.getName() << " This is the grade: " << Bureaucrat.getGrade() << std::endl;
        Bureaucrat.decrementGrade();
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