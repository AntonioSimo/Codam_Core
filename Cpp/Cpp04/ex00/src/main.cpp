#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* beta = new WrongAnimal();
    const WrongAnimal* x = new WrongCat();
    
    std::cout << x->getType() << " " << std::endl;
    x->makeSound();
    beta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    delete beta;
    delete x;
    return (0);
}