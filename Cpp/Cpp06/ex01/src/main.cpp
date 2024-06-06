#include "Serializer.hpp"

int main(void)
{
	Data *mydata = new Data;

	mydata->setData(10);
	std::cout << "This is m_number in Data: " << mydata->getData() << std::endl;
	std::cout << "Value of mydata obj: " << &mydata << std::endl;
	uintptr_t serialized = Serializer::serialize(mydata);
	std::cout << "Result of serialize function: " << serialized << std::endl;
	mydata = Serializer::deserialize(serialized);
	std::cout << "Result of the deserialize function: " << &mydata << std::endl;
	std::cout << "This is m_number in Data: " << mydata->getData() << std::endl;

	delete mydata;

	return (0);
}