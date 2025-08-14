/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:00:24 by gkaim             #+#    #+#             */
/*   Updated: 2025/08/12 15:16:58 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main() 
{
    const int size = 10; // total number of animals
    Animal* animals[size];

    std::cout << "\n--- Creating Animals ---\n";
    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << "\n--- Testing makeSound() ---\n";
    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Testing Deep Copy (Dog) ---\n";
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

    
    std::cout << "\n--- Testing Deep Copy (Cat) ---\n";
    Cat* originalCat = new Cat();
    originalCat->setIdea(0, "Meow at owner");
    originalCat->setIdea(1, "Chase mice");

    Cat* copiedCat = new Cat(*originalCat); // invokes copy constructor

    std::cout << "Original Dog Idea 0: " << originalCat->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0:   " << copiedCat->getIdea(0) << std::endl;

    copiedCat->setIdea(0, "Sleep all day");
    std::cout << "After modifying copied cat...\n";
    std::cout << "Original Dog Idea 0: " << originalCat->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0:   " << copiedCat->getIdea(0) << std::endl;

    delete originalCat;
    delete copiedCat;
    
    std::cout << "\n--- Deleting Animals ---\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "\n--- Finished ---\n";
    return 0;
}

// int main()
// {
//     const int size = 10; // total number of animals
//     Animal* animals[size];

//     std::cout << "\n--- Creating Animals ---\n";
//     for (int i = 0; i < size / 2; ++i)
//         animals[i] = new Dog();
//     for (int i = size / 2; i < size; ++i)
//         animals[i] = new Cat();

//     std::cout << "\n--- Testing makeSound() ---\n";
//     for (int i = 0; i < size; ++i)
//         animals[i]->makeSound();

//     // ===================== DOG DEEP COPY TEST =====================
//     std::cout << "\n--- Testing Dog Deep Copy ---\n";
//     Dog* originalDog = new Dog();
//     originalDog->setIdea(0, "Guard the house");
//     originalDog->setIdea(1, "Eat beef");

//     Dog* copiedDog = new Dog(*originalDog); // invokes Dog copy constructor

//     std::cout << "Original Dog Idea 0: " << originalDog->getIdea(0) << std::endl;
//     std::cout << "Copied Dog Idea 0:   " << copiedDog->getIdea(0) << std::endl;

//     copiedDog->setIdea(0, "Sleep all day");
//     std::cout << "After modifying copied dog...\n";
//     std::cout << "Original Dog Idea 0: " << originalDog->getIdea(0) << std::endl;
//     std::cout << "Copied Dog Idea 0:   " << copiedDog->getIdea(0) << std::endl;

//     delete originalDog;
//     delete copiedDog;

//     // ===================== CAT DEEP COPY TEST =====================
//     std::cout << "\n--- Testing Cat Deep Copy ---\n";
//     Cat* originalCat = new Cat();
//     originalCat->setIdea(0, "Chase mice");
//     originalCat->setIdea(1, "Nap in the sun");

//     Cat* copiedCat = new Cat(*originalCat); // invokes Cat copy constructor

//     std::cout << "Original Cat Idea 0: " << originalCat->getIdea(0) << std::endl;
//     std::cout << "Copied Cat Idea 0:   " << copiedCat->getIdea(0) << std::endl;

//     copiedCat->setIdea(0, "Knock things off table");
//     std::cout << "After modifying copied cat...\n";
//     std::cout << "Original Cat Idea 0: " << originalCat->getIdea(0) << std::endl;
//     std::cout << "Copied Cat Idea 0:   " << copiedCat->getIdea(0) << std::endl;

//     delete originalCat;
//     delete copiedCat;

//     // ===================== EDGE CASE TESTS =====================
//     std::cout << "\n--- Testing Edge Cases ---\n";
//     Dog edgeDog;
//     edgeDog.setIdea(0, "Idea at index 0");
//     edgeDog.setIdea(99, "Idea at index 99");
//     edgeDog.setIdea(100, "Should fail (out of range)"); // test bounds checking

//     std::cout << "Index 0: " << edgeDog.getIdea(0) << std::endl;
//     std::cout << "Index 99: " << edgeDog.getIdea(99) << std::endl;
//     std::cout << "Index 100: " << edgeDog.getIdea(100) << std::endl; // should fail

//     // ===================== DELETE ALL ANIMALS =====================
//     std::cout << "\n--- Deleting Animals ---\n";
//     for (int i = 0; i < size; ++i)
//         delete animals[i];

//     std::cout << "\n--- Finished ---\n";
//     return 0;
// }
