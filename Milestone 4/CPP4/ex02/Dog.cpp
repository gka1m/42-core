/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:19:37 by gkaim             #+#    #+#             */
/*   Updated: 2025/08/19 09:53:15 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Copy Dog created" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog has left" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return brain->getIdea(index);
}