#include "phonebook.hpp"

// void    SearchContact(Contact Phone)
// {
//     Phone.PrintData();
// }

void    GetData(Contact Phone)
{
    Phone.GetFirstName();
    Phone.GetLastName();
    Phone.GetNickName();
    Phone.GetPhoneNumber();
    Phone.GetDarkestSecret();
}

void    Phonebook::PrintData(Phonebook Phonebook)
{
    Contact contact;

    contact = Phonebook.PhonebookContact[0];
     size_t index = 0;
        while (index <= MAXCONTACT)
        {
            std::cout << "This is the First name: " << contact.GetFirstName() << std::endl;
            // std::cout << "This is the Last name: " << Phonebook[index]<< std::endl;
            // std::cout << "This is the Nick name: " << Phonebook[index]<< std::endl;
            // std::cout << "This is the Phone number: " << Phonebook[index] << std::endl;
            // std::cout << "This is the Darkest secret: " << Phonebook[index] << std::endl;
            index++;
        }
}

// void    AddingContact(Contact Phone)
// {
//     Phone.index = 8;

//     for (size_t i = 0; i < Phone.index; i++)
//     {
//         GetData(Phone);
//     }
    
// }

void    PhonebookProgram(Phonebook Phone)
{
    std::string input;

    std::cout << "Welcome in the Phonebook!" << std::endl;
    while (1)
    {
        std::cout << "Select one of the option between: ADD, SEARCH and EXIT" << std::endl;
        std::getline (std::cin, input);
        if (input == "ADD")
            GetData(Phone::PhonebookContact);
        else if (input == "SEARCH")
            Phonebook.PrintData(Phonebook);
        else if (input == "EXIT")
           break;
        else
            std::cout << "You select an invalid option. Please try again!" << std::endl;
    }
}