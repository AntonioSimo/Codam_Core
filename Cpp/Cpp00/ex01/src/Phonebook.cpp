#include "Phonebook.hpp"

std::string Phonebook::getOptions(const std::string &t_option)
{
    std::string line;

    while (1)
    {
        if (!std::cin.good())
            return(line);
        std::cout << "What's your " << t_option << "? ";
        std::getline (std::cin, line);
        if(!line.empty()) //Returns a bool value whether the string is empty 
            return (line);
        else
            std::cerr << t_option << "Cannot be empty." << std::endl;
    }
}

void    Phonebook::setData()
{
    Contact contact; //create an object contact
                     //set the contact attributes of the new contact
    contact.setFirstName(getOptions("First Name"));
    contact.setLastName(getOptions("Last Name"));
    contact.setNickname(getOptions("Nickname"));
    contact.setPhoneNumber(getOptions("Phone number"));
    contact.setDarkestSecret(getOptions("Darkest secret"));
    if (this->m_pos >= MAXCONTACT)
        this->m_pos = 0;
    this->m_phonebookContact[m_pos++] = contact;
    if (this->m_contact < MAXCONTACT)
        this->m_contact++;
}

void    printTab()
{
    std::cout << "\t-------------------------------------------------" << std::endl;
    std::cout << "\t|" << YELLOW << std::setw(10) << "ID" << RESET;
    std::cout << "|" << YELLOW << std::setw(10) << "First name" << RESET; 
    std::cout << "|" << YELLOW << std::setw(10) << "Last name" << RESET; 
    std::cout << "|" << YELLOW << std::setw(10) << "Nick name" << RESET << "\t|" <<std::endl;
    std::cout << "\t-------------------------------------------------" << std::endl;
}

std::string    trunc_string(std::string t_stringToPrint)
{
    std::string trunc;

    trunc = t_stringToPrint.substr(0, 10);
    trunc[9] = '.';
    return (trunc);
}

void    Phonebook::search()
{
    int  i = 0;
    std::string line;

    printTab();
    while (i < this->m_contact)
    {
        std::cout << "\t|" << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << trunc_string(this->m_phonebookContact[i].getFirstName()) << "|";
        std::cout << std::setw(10) << trunc_string(this->m_phonebookContact[i].getLastName()) << "|";
        std::cout << std::setw(10) << trunc_string(this->m_phonebookContact[i].getNickName()) << "\t|" <<std::endl;
        std::cout << "\t-------------------------------------------------" << std::endl;
        i++;
    }

    std::cout << "\n\tDo you want to have more informations about the contacts?" << std::endl;

    std::cout << "\t";
    std::getline (std::cin, line);
    if(line.empty() || !std::cin.good())
        std::cerr << RED << "\tIt's a YES or NO question." << RESET << std::endl;
    if (line == "YES")
    {
        std::cout << "\tSelect the ID to get them." << std::endl;
        std::cout << "\t";
        std::getline (std::cin, line);
        if(!line.empty() || !std::cin.good())
            getContactId(line);
        return;
    }
    if (line == "NO")
        return;
    else
        std::cerr << RED << "\tIt's a YES or NO question or you have to write yes or no in capital letter." << RESET << std::endl;
}

void    Phonebook::getContactId(const std::string t_input)
{
    int x = std::stoi(t_input);//standard library function that turns a string into an integer
    x = x - 1;

    if (x >= 0 && x < this->m_contact)
        m_phonebookContact[x].printInfo();
    else
        std::cerr << RED << "\tYou typed a wrong ID. Try again!" << RESET << std::endl;

}

//Member function defined outside the class definition using the scope resolution operator (::) followed by the
//function name
void    Phonebook::phonebookProgram()
{
    std::cout << "Welcome in the Phonebook!" << std::endl; //write in the standard output
    this->m_pos = 0; //set the attribute pos
    this->m_contact = 0; //set the attribute contact
    while (std::cin.good())
    {
        std::cout << "Select one of the option between: ADD, SEARCH and EXIT." << std::endl;
        std::getline (std::cin, m_input); //read a string or a line from an input stream (cin) and store in the object
                                         //(m_input) after being read from the stream
        if (m_input == "ADD")
        {
            setData(); //member function
            if (std::cin.good())
                std::cout << GREEN << "Contact added successfully!" << RESET << std::endl; //write in the standard output
        }
        else if (m_input == "SEARCH")
            search(); //member function
        else if (m_input == "EXIT")
        {
           break;
        }
        else
            std::cerr << RED << "You select an invalid option. Please try again!" << RESET << std::endl; //write in the
                                                                                                        //standard error
    }
    std::cout << "Thank you to use Phonebook." << std::endl; //write in the standard output
}