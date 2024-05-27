#pragma once

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat; // Forward declaration

class Form
{
private: //Access specifier
	const std::string m_name; //Attribute
		  bool m_signed; //Attribute
	const int m_gradeToSign; //Attribute
	const int m_gradeToExecute; //Attribute

public: //Access specifier
	Form(); //Default Constructor
	Form(std::string t_name, bool t_signed, int t_gradeToSign, int t_gradeToExecute); //Parameterized Constructor
	Form(const Form& obj); //Copy Constructor
	Form& operator=(const Form& obj); //Copy assignment operator overload
	~Form(); //Destructor
	std::string getName() const; //Member function
	bool getSigned() const; //Member function
	int getGradeToSign() const; //Member function
	int getGradeToExecute() const; //Member function
	void beSigned(const Bureaucrat &); //Member function

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

std::ostream& operator<<(std::ostream& t_out, const Form& obj); //overload of the insertion («) operator


