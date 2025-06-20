/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:05:43 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/20 14:17:37 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
    std::cout << "Animal of type " << type << " created" << std::endl;
}

Animal::Animal(const std::string& type) : type(type) 
{
    std::cout << type << " created" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Copy animal " << type << " created!" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Assignment animal of type " << type << " created!" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Sayonara " << type << "!" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Michael Jackson HEEHEE" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}