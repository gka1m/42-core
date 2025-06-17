/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:05:58 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/17 16:26:12 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() : ClapTrap("Scav_gkaim", 100, 50, 20) 
{
    std::cout << "Default Scav constructed" << std::endl;
}

// Param Constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "Scav " << name << " constructed" << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "Copy Scav " << getName() << " constructed" << std::endl;
}

// Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "Scav " << getName() << " assigned" << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {}

void ScavTrap::attack(const std::string& target)
{
    if (getHP() <= 0 || getEnergy() <= 0)
    {
        std::cout << getName() << " has no energy or dead" << std::endl;
        return;
    }
    decreaseEnergy();
    std::cout << getName() << "attacks " << target << " brutally with " << getDmg() << " damage" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << getName() << " has entered Gate Keeper mode!" << std::endl;
}
