/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:00:24 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/20 14:55:43 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const WrongAnimal* meta = new WrongAnimal();
//     const Animal* j = new Dog();
//     const WrongAnimal* i = new WrongCat();

//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();

//     delete i;
//     delete j;
//     delete meta;

//     return 0;
// }

int main()
{
    std::cout << "=== Testing Proper Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;  // Dog
    std::cout << cat->getType() << std::endl;  // Cat
    dog->makeSound();                          // Woof!
    cat->makeSound();                          // Meow!
    meta->makeSound();                         // Animal sound (if defined)

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Testing Wrong Polymorphism ===" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongAnimal->getType() << std::endl; // WrongAnimal
    std::cout << wrongCat->getType() << std::endl;    // WrongCat
    wrongAnimal->makeSound();                         // Generic WrongAnimal sound
    wrongCat->makeSound();                            // ❌ Will call WrongAnimal::makeSound() if not virtual

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}