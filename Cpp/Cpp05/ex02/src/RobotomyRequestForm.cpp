#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), m_target("default")
{
	std::cout << "Default RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string t_target) : AForm("RobotomyRequestForm", false, 72, 45), m_target(t_target)
{
	std::cout << MAGENTA << "Parameterized RobotomyRequestForm constructor called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
    std::cout << "Copy RobotomyRequestForm constructor called." << std::endl;

    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
    {
        this->m_target = obj.m_target;
    }
    std::cout << "Copy RobotomyRequestForm assignment operator called." << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "Destructor RobotomyRequestForm called." << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
    AForm::execute(executor);
    
    std::cout << m_target << " has been robotomized successfully 50% of the time." << std::endl;
}