#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
    return (0);
}