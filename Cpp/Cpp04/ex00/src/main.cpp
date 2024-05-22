#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* hachiko = new Dog();
    const Animal* tom = new Cat();

    std::cout << hachiko->getType() << " " << std::endl;
    std::cout << tom->getType() << " " << std::endl;
    tom->makeSound();
    hachiko->makeSound();
    meta->makeSound();

    const WrongAnimal* beta = new WrongAnimal();
    const WrongAnimal* x = new WrongCat();
    
    std::cout << x->getType() << " " << std::endl;
    x->makeSound();
    beta->makeSound();
    
    delete meta;
    delete hachiko;
    delete tom;
    delete beta;
    delete x;
    return (0);
}