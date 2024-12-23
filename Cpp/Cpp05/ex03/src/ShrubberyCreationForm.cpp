#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), m_target("default")
{
	std::cout << "Default ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t_target) : AForm("ShrubberyCreationForm", false, 145, 137), m_target(t_target)
{
	std::cout << MAGENTA << "Parameterized ShrubberyCreationForm constructor called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
    std::cout << "Copy ShrubberyCreationForm constructor called." << std::endl;

    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        this->m_target = obj.m_target;
    }
    std::cout << "Copy ShrubberyCreationForm assignment operator called." << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "Destructor ShrubberyCreationForm called." << RESET << std::endl;
}

void ShrubberyCreationForm::execution()
{
    std::fstream    File;
    std::string     FileName;

    FileName = m_target.append("_shrubbery");
    File.open(FileName, std::ios::trunc | std::ios::out);

    File << "            .        +          .      .          .\n"
                 "     .            _        .                    .\n"
                 "  ,              /;-._,-.____        ,-----.__\n"
                 " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
                 "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
                 "                      ,    `./  \\:. `.   )==-'  .\n"
                 "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
                 ".           \\:/'`-' , ,\\ '` ` `   ): , /_  -o\n"
                 "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
                 "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
                 "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
                 "              \\:  `  X` _| _,\\/\'   .-'\n"
                 ".               \":._:`\\____  /:'  /      .           .\n"
                 "                    \\::.  :\\/:'  /              +\n"
                 "   .                 `.:.  /:'  }      .\n"
                 "           .           ):_(:;   \\           .\n"
                 "                      /:. _/ ,  |\n"
                 "                   . (|::.     ,`                  .\n"
                 "     .                |::.    {\\\n"
                 "                      |::.  \\ `.\n"
                 "                      |:::(\\    |\n"
                 "              O       |:::/{ }  |                  (o\n"
                 "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
                 "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
                 "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~\"";

    File.close();
}
