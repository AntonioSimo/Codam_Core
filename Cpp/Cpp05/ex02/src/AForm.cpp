#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : m_name("default"), m_signed(false), m_gradeToSign(MIN_GRADE), m_gradeToExecute(MIN_GRADE)
{
	std::cout << "Default AForm constructor called." << std::endl;
}

AForm::AForm(std::string t_name, bool t_signed, int t_gradeToSign, int t_gradeToExecute) : m_name(t_name), m_signed(t_signed), m_gradeToSign(t_gradeToSign), m_gradeToExecute(t_gradeToExecute) 
{
    if (t_gradeToSign < MAX_GRADE || t_gradeToExecute < MAX_GRADE)
        throw(GradeTooHighException());
    else if (t_gradeToSign > MIN_GRADE || t_gradeToExecute > MIN_GRADE)
        throw(GradeTooLowException());
    std::cout << MAGENTA << "Parameterized AForm constructor called." << RESET << std::endl;
}

AForm::AForm(const AForm& obj) : m_name(obj.m_name), m_signed(obj.m_signed), m_gradeToSign(obj.m_gradeToSign), m_gradeToExecute(obj.m_gradeToExecute)
{
    std::cout << "Copy AForm constructor called." << std::endl;

    *this = obj;
}

AForm& AForm::operator=(const AForm& obj)
{
    if (this != &obj)
    {
        this->m_signed = obj.m_signed;
    }
    std::cout << "Copy AForm assignment operator called." << std::endl;
    return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "Destructor AForm called." << RESET << std::endl;
}

std::string AForm::getName() const
{
	return (this->m_name);
}

bool AForm::getSigned() const
{
	return (this->m_signed);
}

int AForm::getGradeToSign() const
{
	return (this->m_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->m_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &t_bureaucrat)
{

	if (t_bureaucrat.getGrade() > getGradeToSign())
	{
		std::cout << CYAN << t_bureaucrat.getName() << " bureaucrat can't sign the Form." << RESET << std::endl;
		m_signed = false;
        throw GradeTooLowException();
	}
	m_signed = true;
}

std::ostream& operator<<(std::ostream& t_out, const AForm& obj)
{
    return (t_out << obj.getName()) << ", Form grade to sign: " << obj.getGradeToSign() << ". Grade to execute: " << obj.getGradeToExecute() << ". Form is signed " << obj.getSigned() << std::endl;
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade too low Exception");
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade too high Exception") ;
}

void AForm::execute(Bureaucrat const & t_executor)
{
    if (t_executor.getGrade() > this->getGradeToExecute())
        throw (GradeTooLowException());
    this->execution();
    if (m_signed == true)
        std::cout << "The " << m_name << " is signed." << std::endl;
    else
        std::cout << "The " << m_name << " is not executed because is not signed." << std::endl;
}