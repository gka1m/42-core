/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:00:24 by gkaim             #+#    #+#             */
/*   Updated: 2025/08/14 12:17:25 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main() 
{
    const int size = 10; // total number of animals
    Animal* animals[size];
    // Animal* testAnimal = new Animal();  //uncomment to check for abstraction of class (should not compile)

    std::cout << "\n--- Creating Animals ---\n";
    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << "\n--- Testing makeSound() ---\n";
    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Testing Deep Copy ---\n";
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "Guard the house");
    originalDog->setIdea(1, "Eat beef");

    Dog* copiedDog = new Dog(*originalDog); // invokes copy constructor

    std::cout << "Original Dog Idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0:   " << copiedDog->getIdea(0) << std::endl;

    copiedDog->setIdea(0, "Sleep all day");
    std::cout << "After modifying copied dog...\n";
    std::cout << "Original Dog Idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0:   " << copiedDog->getIdea(0) << std::endl;

    delete originalDog;
    delete copiedDog;

    std::cout << "\n--- Deleting Animals ---\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "\n--- Finished ---\n";
    return 0;
}