/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:04:55 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/23 12:30:06 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
    std::cout << "Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << type << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout << "Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructed" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}