/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:34:55 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/20 14:36:09 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown")
{
    std::cout << "Wrong Animal of type " << type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) 
{
    std::cout << type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "Copy animal " << type << " created!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Assignment animal of type " << type << " created!" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Sayonara " << type << "!" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Annyeonghaseyo" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}