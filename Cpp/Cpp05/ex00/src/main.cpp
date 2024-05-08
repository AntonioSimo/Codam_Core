#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat Bureaucrat("Antonio", 0);

    // try
    // {
    //     if (Bureaucrat.getGrade() >= 1 && Bureaucrat.getGrade() <= 150)
    //     {
             std::cout << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
    //     }
    //     else
    //     {
    //         std::string name = Bureaucrat.getName();
    //         throw(name);
    //     }
    // }
    // catch (std::exception & e)
    // {
    //     // if (Bureaucrat.getGrade() > 150)
    //     // {
    //         // std::cout << Bureaucrat.getName() << ", bureaucrat grade is too low" << std::endl;
    //     std::cout << "The grade is: " << e.what() << std::endl;    
    //     // }
    //     // else
    //     // {
    //     //     std::cout << "it doesn't exist an higher level then 1." << std::endl;
    //     // }
    // }
    return (0);
}