#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat Bureaucrat1("Antonio", 12654504265);
        //Bureaucrat Bureaucrat2("Jack", 170);
        //Bureaucrat Bureaucrat3("Paul", 0);
        
        std::cout << GREEN << Bureaucrat1.getName() << " This is the grade when initialized: " << Bureaucrat1.getGrade() << RESET << std::endl;
        // Bureaucrat1.incrementGrade();
        // std::cout << YELLOW << Bureaucrat1.getName() << " This is the grade after increment it: " << Bureaucrat1.getGrade() << RESET << std::endl;
        // Bureaucrat1.incrementGrade();
        // std::cout << YELLOW << Bureaucrat1.getName() << " This is the grade after increment it: " << Bureaucrat1.getGrade() << RESET << std::endl;
        // Bureaucrat1.incrementGrade();
        // std::cout << YELLOW << Bureaucrat1.getName() << " This is the grade after increment it: " << Bureaucrat1.getGrade() << RESET << std::endl;
        // Bureaucrat1.decrementGrade();
        // std::cout << CYAN << Bureaucrat1.getName() << " This is the grade after decrement it: " << Bureaucrat1.getGrade() << RESET << std::endl;
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