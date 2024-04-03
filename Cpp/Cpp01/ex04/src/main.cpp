#include "filename.hpp"

int main(int argc, char* argv[])
{
    (void) argc;
    std::string   file = argv[1];
    std::string   s1 = argv[2];
    std::string   s2 = argv[3];
    file.append(".replace");

    std::ofstream newFile(file);

    newFile << s1.swap(s2);

    newFile.close();

    // std::string   myText;

    // std::ifstream fileToRead(file);
    // while (getline(fileToRead, myText))
    // {                                  
    //     std::cout << myText << std::endl;
    // }  
    // fileToRead.close();
    //std::cout << file << std::endl;
}

// int main()
// {
//     std::string   myText; //create a text string, which is used to output the text file

//     std::ofstream NewFile("filename.txt"); //create and open a text file

//     NewFile << "Hello World! My name is The Real Slim Shady."; //write to the file

//     NewFile.close(); //close the file

//     std::ifstream MyReadFile("filename.txt"); //read from the text file

//     while (getline(MyReadFile, myText)) //Use a while loop together with the getline() 
//     {                                   //function to read the file line by line
//         std::cout << myText << std::endl; //output the text from the file
//     }
    
//     MyReadFile.close(); //close the file
// }