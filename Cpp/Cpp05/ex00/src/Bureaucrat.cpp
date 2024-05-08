#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string t_name, int t_grade) : m_name(t_name), m_grade(setGrade(t_grade))
{
    std::cout << MAGENTA <<"Parameterized ClapTrap constructor called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
    std::cout << "Copy Bureaucrat constructor called." << std::endl;

    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
    {
        this->m_grade = obj.m_grade;
    }
    std::cout << "Copy Bureaucrat assignment operator called." << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor Bureaucrat called." << std::endl;
}


int Bureaucrat::getGrade()
{
    return (this->m_grade);
}

std::string Bureaucrat::getName()
{
    return (this->m_name);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low Exception");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high Exception") ;
}

int Bureaucrat::setGrade(int t_grade)
{
    m_grade = t_grade;
    return (m_grade);
}

// void    Bureaucrat::gradeCheck(int t_grade)
// {
    
// }