#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"


int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* animals[100];

    for (size_t x = 0; x < 100; x++)
    {
        if (x % 2)
            animals[x] = new Dog();
        else
            animals[x] = new Cat();
    }
    
    for (size_t z = 0; z < 100; z++)
        delete animals[z];

    delete j;
    delete i;
    return (0);
}