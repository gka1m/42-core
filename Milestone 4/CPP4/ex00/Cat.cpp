/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:58:39 by gkaim             #+#    #+#             */
/*   Updated: 2025/08/12 11:34:09 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    type = "Cat";
    std::cout << "Cat created" << std::endl;
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

Cat::~Cat()
{
    std::cout << "Cat is going off" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
