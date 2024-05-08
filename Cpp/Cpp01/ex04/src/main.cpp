#include "filename.hpp"

int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        std::string   file = argv[1];
        std::string   s1 = argv[2];
        std::string   s2 = argv[3];
        std::string   buffer; //create a text string, which is used to copy the text inside argv[1]
        std::string   new_string;

        std::ifstream fileToRead(file); //read from the text file 
        if (!fileToRead) //if the reading fails
        {
            std::cerr << "Error: Unable to open the input file." << std::endl;
            return (1);
        }
        file.append(".replace"); //add the string ".replace" to the filename
        std::ofstream newFile(file); //create and open a text file
        if (!newFile) //if the creation fails
        {
            std::cerr << "Error: Unable to create the new file." << std::endl;
            return (1);
        }
        while (getline(fileToRead, buffer)) //read all the file lines and write into buffer.
        {
            size_t        pos = 0;
            while ((pos = buffer.find(s1, pos)) != std::string::npos) //std::string::npos = "until the end of the string."
            {                                                         //It's the greatest possible value for an element of type size_t.
                buffer.erase(pos, s1.length()); //delete the s1
                buffer.insert(pos, s2); //put the s2 in the s1 pos
                pos += s2.length(); // Move past the replaced substring
            }
            newFile << buffer << std::endl; //write the buffer content in newFile
        }
        fileToRead.close(); //close the file to read
        newFile.close(); //close the file to write
    }
    else
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <stringtoreplace> <newstring>" << std::endl;
        return (1);
    }
}
