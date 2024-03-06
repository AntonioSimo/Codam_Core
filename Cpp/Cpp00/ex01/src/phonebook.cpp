#include "phonebook.hpp"

std::string getOptions(const std::string &option)
{
    std::string line;

    while (1)
    {
        std::cout << "What's your " << option << "? ";
        std::getline (std::cin, line);
        if(!line.empty())
            return (line);
        else
            std::cout << option << "cannot be empty." << std::endl;
    }
}

void    Phonebook::setData()
{
    int i = this->contact;

    Contact contact;
    
    
    contact.SetFirstName(getOptions("First Name"));
    contact.SetLastName(getOptions("Last Name"));
    contact.SetNickName(getOptions("Nickname"));
    contact.SetPhoneNumber(getOptions("Phone number"));
    contact.SetDarkestSecret(getOptions("Darkest secret"));
    this->PhonebookContact[i] = contact;
    if (this->contact >= MAXCONTACT)
        pos = 0;
    else
    {
        pos++;
        this->contact++;
    }
}

void    Phonebook::SearchContact()
{
    size_t  i = 0;

    while (i < this->contact)
    {
        std::cout << "This is the First name: " << this->PhonebookContact[i].GetFirstName() << std::endl;
        std::cout << "This is the Last name: " << this->PhonebookContact[i].GetLastName() << std::endl;
        std::cout << "This is the Nick name: " << this->PhonebookContact[i].GetNickName() << std::endl;
        std::cout << "This is the Phone number: " << this->PhonebookContact[i].GetPhoneNumber() << std::endl;
        std::cout << "This is the Darkest secret: " << this->PhonebookContact[i].GetDarkestSecret() << std::endl;
        i++;
    }
}

void    Phonebook::PhonebookProgram()
{
    std::string input;

    std::cout << "Welcome in the Phonebook!" << std::endl;
    pos = 0;
    this->contact = 0;
    while (1)
    {
        std::cout << "Select one of the option between: ADD, SEARCH and EXIT" << std::endl;
        std::getline (std::cin, input);
        if (input == "ADD")
        {
            setData();
            std::cout << "\033[32mContact added successfully!\033[0m" << std::endl;
        }
        else if (input == "SEARCH")
            SearchContact();
        else if (input == "EXIT")
           break;
        else
            std::cout << "You select an invalid option. Please try again!" << std::endl;
    }
}