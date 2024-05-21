#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : m_name("default"), m_signed(false), m_gradeToSign(MIN_GRADE), m_gradeToExecute(MIN_GRADE)
{
	std::cout << "Default Form constructor called." << std::endl;
}

Form::Form(std::string t_name, bool t_signed, int t_gradeToSign, int t_gradeToExecute) : m_name(t_name), m_signed(t_signed), m_gradeToSign(t_gradeToSign), m_gradeToExecute(t_gradeToExecute) 
{
    if (t_gradeToSign < MAX_GRADE || t_gradeToExecute < MAX_GRADE)
        throw(GradeTooHighException());
    else if (t_gradeToSign > MIN_GRADE || t_gradeToExecute > MIN_GRADE)
        throw(GradeTooLowException());
    std::cout << MAGENTA << "Parameterized Form constructor called." << RESET << std::endl;
}

Form::Form(const Form& obj) : m_name(obj.m_name), m_signed(obj.m_signed), m_gradeToSign(obj.m_gradeToSign), m_gradeToExecute(obj.m_gradeToExecute)
{
    std::cout << "Copy Form constructor called." << std::endl;

    *this = obj;
}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
        this->m_signed = obj.m_signed;
    }
    std::cout << "Copy Form assignment operator called." << std::endl;
    return (*this);
}

Form::~Form()
{
	std::cout << RED << "Destructor Form called." << RESET << std::endl;
}

std::string Form::getName() const
{
	return (this->m_name);
}

bool Form::getSigned() const
{
	return (this->m_signed);
}

int Form::getGradeToSign() const
{
	return (this->m_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->m_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &b)
{

	if (b.getGrade() > getGradeToSign())
	{
		std::cout << CYAN << b.getName() << " bureaucrat can't sign the Form." << RESET << std::endl;
		m_signed = false;
        throw GradeTooLowException();
	}
	m_signed = true;
}

std::ostream& operator<<(std::ostream& t_out, const Form& obj)
{
    return (t_out << obj.getName()) << ", Form grade to sign: " << obj.getGradeToSign() << ". Grade to execute: " << obj.getGradeToExecute() << ". Form is signed " << obj.getSigned() << std::endl;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low Exception");
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high Exception") ;
}