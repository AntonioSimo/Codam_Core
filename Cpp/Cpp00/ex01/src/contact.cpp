#include "contact.hpp"

//scope operator (::, two colons) Here it is used in the definition of functions set... get... and get_values to define
//member of a class (Contact) outside the class itself.

//this->
std::string  Contact::getFirstName()
{
	return(this->_firstName);
}

std::string  Contact::getLastName()
{
	return(this->_lastName);
}

std::string  Contact::getNickName()
{
	return(this->_nickname);
}

std::string  Contact::getPhoneNumber()
{
	return(this->_phoneNumber);
}

std::string  Contact::getDarkestSecret()
{
	return(this->_darkestSecret);
}

void  Contact::setFirstName(const std::string &firstName)
{
   this->_firstName = firstName; //assigns the value of firstname to the _firstName data member of the current object
}

void  Contact::setLastName(const std::string &lastName)
{
	this->_lastName = lastName;
}

void  Contact::setNickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

void  Contact::setPhoneNumber(const std::string &PhoneNumber)
{
	this->_phoneNumber = PhoneNumber;
}

void  Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void    Contact::printInfo()
{
    std::cout << "\tFirst Name: " << this->_firstName << std::endl;
    std::cout << "\tLast Name: " << this->_lastName << std::endl;
    std::cout << "\tNickname: " << this->_nickname << std::endl;
    std::cout << "\tPhone number: " << this->_phoneNumber << std::endl;
    std::cout << "\tDarkest secret: " << this->_darkestSecret << std::endl;
}