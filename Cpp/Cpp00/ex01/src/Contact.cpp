#include "Contact.hpp"

//scope operator (::, two colons) Here it is used in the definition of functions set... get... and get_values to define
//member of a class (Contact) outside the class itself.

//this->
std::string  Contact::getFirstName()
{
	return(this->m_firstName);
}

std::string  Contact::getLastName()
{
	return(this->m_lastName);
}

std::string  Contact::getNickName()
{
	return(this->m_nickname);
}

std::string  Contact::getPhoneNumber()
{
	return(this->m_phoneNumber);
}

std::string  Contact::getDarkestSecret()
{
	return(this->m_darkestSecret);
}

void  Contact::setFirstName(const std::string &t_firstName)
{
   this->m_firstName = t_firstName; //assigns the value of firstname to the m_firstName data member of the current object
}

void  Contact::setLastName(const std::string &t_lastName)
{
	this->m_lastName = t_lastName;
}

void  Contact::setNickname(const std::string &t_nickname)
{
	this->m_nickname = t_nickname;
}

void  Contact::setPhoneNumber(const std::string &t_PhoneNumber)
{
	this->m_phoneNumber = t_PhoneNumber;
}

void  Contact::setDarkestSecret(const std::string &t_darkestSecret)
{
	this->m_darkestSecret = t_darkestSecret;
}

void    Contact::printInfo()
{
    std::cout << "\tFirst Name: " << this->m_firstName << std::endl;
    std::cout << "\tLast Name: " << this->m_lastName << std::endl;
    std::cout << "\tNickname: " << this->m_nickname << std::endl;
    std::cout << "\tPhone number: " << this->m_phoneNumber << std::endl;
    std::cout << "\tDarkest secret: " << this->m_darkestSecret << std::endl;
}