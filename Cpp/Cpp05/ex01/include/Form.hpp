#pragma once

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat; // Forward declaration

class Form
{
private:
	const std::string m_name;
		  bool m_signed;
	const int m_gradeToSign;
	const int m_gradeToExecute;
public:
	Form(); //Default Constructor
	Form(std::string t_name, bool t_signed, int t_gradeToSign, int t_gradeToExecute); //Parameterized Constructor
	Form(const Form& obj); //Copy Constructor
	Form& operator=(const Form& obj); //Copy assignment operator overload
	~Form(); //Destructor
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &);

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


