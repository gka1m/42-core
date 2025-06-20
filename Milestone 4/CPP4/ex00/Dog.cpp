/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:19:37 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/20 14:26:43 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    type = "Dog";
    // std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    *this = other;
    std::cout << "Copy Dog created" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog() {}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
