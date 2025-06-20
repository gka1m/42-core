/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:58:39 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/20 14:26:54 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    type = "Cat";
    // std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    *this = other;
    std::cout << "Copy Cat created" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
