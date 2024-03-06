#include "contact.hpp"

    std::string  Contact::GetFirstName()
    {
	   return(this->_firstName);
    }

    std::string  Contact::GetLastName()
    {
		return(this->_lastName);
    }

    std::string  Contact::GetNickName()
    {
		return(this->_nickname);
    }

    std::string  Contact::GetPhoneNumber()
    {
		return(this->_phoneNumber);
    }

    std::string  Contact::GetDarkestSecret()
    {
		return(this->_darkestSecret);
    }

	void  Contact::SetFirstName(const std::string &element)
    {
	   this->_firstName = element;
    }

    void  Contact::SetLastName(const std::string &element)
    {
		this->_lastName = element;
    }

    void  Contact::SetNickName(const std::string &element)
    {
		this->_nickname = element;
    }

    void  Contact::SetPhoneNumber(const std::string &element)
    {
		this->_phoneNumber = element;
    }

    void  Contact::SetDarkestSecret(const std::string &element)
    {
		this->_darkestSecret = element;
    }