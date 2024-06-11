#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("default"), m_grade(MIN_GRADE)
{
    std::cout << "Default Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string t_name, int t_grade) : m_name(t_name), m_grade(t_grade)
{
    if (t_grade < MAX_GRADE)
        throw(GradeTooLowException());
    else if (t_grade > MIN_GRADE)
        throw(GradeTooHighException());
    std::cout << MAGENTA <<"Parameterized Bureaucrat constructor called." << RESET << std::endl;
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
    std::cout << RED << "Destructor Bureaucrat called." << RESET << std::endl;
}

int Bureaucrat::getGrade() const
{
    return (this->m_grade);
}

std::string Bureaucrat::getName() const
{
    return (this->m_name);
}

void Bureaucrat::incrementGrade()
{
    if (this->m_grade - 1 < MAX_GRADE)
        throw(GradeTooHighException());
    this->m_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->m_grade + 1 > MIN_GRADE)
        throw(GradeTooLowException());
    this->m_grade++;
}

void Bureaucrat::signForm(Form &t_form) const
{
    try
    {
        t_form.beSigned((const Bureaucrat&) *this);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    // if (t_form.getSigned() == true)
        std::cout << CYAN << getName() << " bureaucrat signed form " << t_form.getName() << RESET << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat grade too low Exception");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat grade too high Exception") ;
}

std::ostream& operator<<(std::ostream& t_out, const Bureaucrat& obj)
{
    return (t_out << obj.getName()) << ", bureaucrat grade " << obj.getGrade() << std::endl;
}