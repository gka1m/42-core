/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:46:58 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/17 16:53:30 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap()
    : ClapTrap("diamond_clap_name_default", 100, 50, 30), ScavTrap(), FragTrap(), // Use Frag's hp/dmg, Scav's energy
      name("diamond_default")
{
    std::cout << "Default Diamond constructed" << std::endl;
}

// Param constructor
DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name", 100, 50, 30),
    ScavTrap(), FragTrap(), name(name)
{
    std::cout << "Diamond " << name << " constructed" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "Diamond copy " << name + "_copy" << " constructed" << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
    }
    std::cout << "Diamond " << name + "_assigned" << " assigned" << std::endl;
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {}

// Attack using ScavTrap's attack
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

// whoAmI
void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << name
              << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}