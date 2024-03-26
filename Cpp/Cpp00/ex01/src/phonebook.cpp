#include "phonebook.hpp"

std::string GetOptions(const std::string &option)
{
    std::string line;

    while (1)
    {
        std::cout << "What's your " << option << "? ";
        std::getline (std::cin, line);
        if(!line.empty())
            return (line);
        else
            std::cout << option << "Cannot be empty." << std::endl;
    }
}

void    Phonebook::setData()
{
    Contact contact;

    contact.SetFirstName(GetOptions("First Name"));
    contact.SetLastName(GetOptions("Last Name"));
    contact.SetNickName(GetOptions("Nickname"));
    contact.SetPhoneNumber(GetOptions("Phone number"));
    contact.SetDarkestSecret(GetOptions("Darkest secret"));
    if (pos >= MAXCONTACT)
        pos = 0;
    this->PhonebookContact[pos++] = contact;
    if (this->contact < MAXCONTACT)
        this->contact++;
}

void    PrintTab()
{
    std::cout << "\t-------------------------------------------------" << std::endl;
    std::cout << "\t|" << YELLOW << std::setw(10) << "ID" << RESET;
    std::cout << "|" << YELLOW << std::setw(10) << "First name" << RESET; 
    std::cout << "|" << YELLOW << std::setw(10) << "Last name" << RESET; 
    std::cout << "|" << YELLOW << std::setw(10) << "Nick name" << RESET << "\t|" <<std::endl;
    std::cout << "\t-------------------------------------------------" << std::endl;
}

void    Phonebook::Search()
{
    int  i = 0;
    std::string line;

    PrintTab();
    while (i < this->contact)
    {
        std::cout << "\t|" << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << this->PhonebookContact[i].GetFirstName() << "|";
        std::cout << std::setw(10) << this->PhonebookContact[i].GetLastName() << "|";
        std::cout << std::setw(10) << this->PhonebookContact[i].GetNickName() << "\t|" <<std::endl;
        std::cout << "\t-------------------------------------------------" << std::endl;
        i++;
    }

    std::cout << "\n\tDo you want to have more informations about the contacts?" << std::endl;

    std::cout << "\t";
    std::getline (std::cin, line);
    if(line.empty())
        std::cout << RED << "\tIt's a YES or NO question." << RESET << std::endl;
    if (line == "YES")
    {
        std::cout << "\tSelect the ID to get them." << std::endl;
        std::cout << "\t";
        std::getline (std::cin, line);
        if(!line.empty())
            GetContactId(line);
        return;
    }
    if (line == "NO")
        return;
    else
        std::cout << RED << "\tIt's a YES or NO question or you have to write yes or no in capital letter." << RESET << std::endl;
}

void    Phonebook::GetContactId(const std::string input)
{
    int x = std::stoi(input);
    x = x - 1;

    if (x >= 0 && x < this->contact)
        PhonebookContact[x].PrintInfo();
    else
        std::cout << RED << "\tYou typed a wrong ID. Try again!" << RESET << std::endl;

}

void    Contact::PrintInfo()
{
    std::cout << "\tFirst Name: " << this->_firstName << std::endl;
    std::cout << "\tLast Name: " << this->_lastName << std::endl;
    std::cout << "\tNickname: " << this->_nickname << std::endl;
    std::cout << "\tPhone number: " << this->_phoneNumber << std::endl;
    std::cout << "\tDarkest secret: " << this->_darkestSecret << std::endl;
}

void    Phonebook::PhonebookProgram()
{
    std::string input;

    std::cout << "Welcome in the Phonebook!" << std::endl;
    pos = 0;
    this->contact = 0;
    while (1)
    {
        std::cout << "Select one of the option between: ADD, SEARCH and EXIT." << std::endl;
        std::getline (std::cin, input);
        if (input == "ADD")
        {
            setData();
            std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
        }
        else if (input == "SEARCH")
            Search();
        else if (input == "EXIT")
        {
           std::cout << "Thank you to use Phonebook." << std::endl;
           break;
        }
        else
            std::cout << RED << "You select an invalid option. Please try again!" << RESET << std::endl;
    }
}