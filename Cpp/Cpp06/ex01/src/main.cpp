#include "Serializer.hpp"

int main(void)
{
	Data mydata(15);

	std::cout << "This is m_number in Data: " << mydata.m_number << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&mydata);
	std::cout << "Value of mydata obj: " << &mydata << std::endl;
	std::cout << "Result of serialize function: " << serialized << std::endl;

	Data* deserialize = Serializer::deserialize(serialized);
	std::cout << "Result of the deserialize function: " << deserialize << std::endl;
	std::cout << "This is m_number in Data: " << deserialize->m_number << std::endl;

	if (deserialize == &mydata) 
    	std::cout << GREEN << "Success: The deserialized pointer matches the original pointer." << RESET << std::endl;
	else 
        std::cout << RED << "Error: The deserialized pointer does not match the original pointer." << RESET << std::endl;

	return (0);
}