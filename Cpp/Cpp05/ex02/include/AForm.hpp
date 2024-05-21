#pragma once

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat; // Forward declaration

class AForm
{
private:
	const std::string m_name;
		  bool m_signed;
	const int m_gradeToSign;
	const int m_gradeToExecute;
public:
	AForm(); //Default Constructor
	AForm(std::string t_name, bool t_signed, int t_gradeToSign, int t_gradeToExecute); //Parameterized Constructor
	AForm(const AForm& obj); //Copy Constructor
	virtual AForm& operator=(const AForm& obj); //Copy assignment operator overload
	virtual ~AForm(); //Destructor
	virtual std::string getName() const;
	virtual bool getSigned() const;
	virtual int getGradeToSign() const;
	virtual int getGradeToExecute() const;
	virtual void beSigned(const Bureaucrat &);

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


