#pragma once

#include <iostream>
#include <cstdlib> 
#include <ctime> 

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat; // Forward declaration

class AForm //Abstract class
{
private: //Access specifier
	const std::string m_name; //Attribute
		  bool m_signed; //Attribute
	const int m_gradeToSign; //Attribute
	const int m_gradeToExecute; //Attribute

public: //Access specifier
	AForm(); //Default Constructor
	AForm(std::string t_name, bool t_signed, int t_gradeToSign, int t_gradeToExecute); //Parameterized Constructor
	AForm(const AForm& obj); //Copy Constructor
	AForm& operator=(const AForm& obj); //Copy assignment operator overload
	virtual ~AForm(); //Destructor
	std::string getName() const; //Member function
	bool getSigned() const; //Member function
	int getGradeToSign() const; //Member function
	int getGradeToExecute() const; //Member function
	void beSigned(const Bureaucrat &t_bureaucrat); //Member function
	void execute(Bureaucrat const & t_executor); //Member function
	virtual void execution() = 0; //Pure virtual function

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

std::ostream& operator<<(std::ostream& t_out, const AForm& obj); //overload of the insertion («) operator
