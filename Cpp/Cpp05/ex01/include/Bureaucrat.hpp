#pragma once

#include <iostream>
#include "Form.hpp"

#define CYAN	"\033[36m"
#define GREEN	"\033[32m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat //Base Class
{
private: //Access specifier
	const std::string	m_name; //Attribute
				int		m_grade; //Attribute

public: //Access specifier
	Bureaucrat(); //Default Constructor
	Bureaucrat(std::string t_name, int t_grade); //Parameterized Constructor
	Bureaucrat(const Bureaucrat& obj); //Copy Constructor
	Bureaucrat& operator=(const Bureaucrat& obj); //Copy assignment operator overload
	~Bureaucrat(); //Destructor
	std::string getName() const; //Member function
	int		getGrade() const; //Member function
	void	gradeCheck(int t_grade); //Member function
	void 	incrementGrade(); //Member function
	void	decrementGrade(); //Member function
	void	signForm(Form &t_form) const; //Member function

	class GradeTooHighException : public std::exception //Exception Class
	{
    public: //Access specifier
    	const char *what() const throw(); //Member function
    };
    class GradeTooLowException : public std::exception //Exception Class
	{
    public: //Access specifier
        const char *what() const throw(); //Member function
    };
};

std::ostream& operator<<(std::ostream& t_out, const Bureaucrat& obj); //overload of the insertion («) operator
