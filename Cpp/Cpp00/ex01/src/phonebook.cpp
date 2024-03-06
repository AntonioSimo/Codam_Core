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
    Contact contact;

    contact.SetFirstName(getOptions("First Name"));
    contact.SetLastName(getOptions("Last Name"));
    contact.SetNickName(getOptions("Nickname"));
    contact.SetPhoneNumber(getOptions("Phone number"));
    contact.SetDarkestSecret(getOptions("Darkest secret"));
    if (pos >= MAXCONTACT)
        pos = 0;
    this->PhonebookContact[pos++] = contact;
    if (this->contact < MAXCONTACT)
        this->contact++;
}

void    PrintTab()
{
    std::cout << "\t-------------------------------------------------" << std::endl;
    std::cout << "\t\033[33mID\t";
    std::cout << "First name\t"; 
    std::cout << "Last name\t"; 
    std::cout << "Nick name\033[0m" << std::endl;
    std::cout << "\t-------------------------------------------------" << std::endl;
}

void    Phonebook::SearchContact()
{
    int  i = 0;

    PrintTab();
    while (i < this->contact)
    {
        std::cout << "Phone number: "; 
        std::cout << "Darkest secret: "; 
        std::cout << this->PhonebookContact[i].GetFirstName() << std::endl;
        std::cout << this->PhonebookContact[i].GetLastName() << std::endl;
        std::cout << this->PhonebookContact[i].GetNickName() << std::endl;
        std::cout << this->PhonebookContact[i].GetPhoneNumber() << std::endl;
        std::cout << this->PhonebookContact[i].GetDarkestSecret() << std::endl;
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
            std::cout << "\033[31mYou select an invalid option. Please try again!\033[0m" << std::endl;
    }
}