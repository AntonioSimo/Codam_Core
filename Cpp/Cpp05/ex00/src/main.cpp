#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat Bureaucrat1("Antonio", 2);
        //Bureaucrat Bureaucrat2("Jack", 170);
        //Bureaucrat Bureaucrat3("Paul", 0);
        
        std::cout << GREEN << Bureaucrat1 << RESET;
        // Bureaucrat1.incrementGrade();
        // std::cout << YELLOW << Bureaucrat1 << RESET;
        // Bureaucrat1.incrementGrade();
        // std::cout << YELLOW << Bureaucrat1 << RESET;
        // Bureaucrat1.decrementGrade();
        // std::cout << CYAN << Bureaucrat1 << RESET;
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