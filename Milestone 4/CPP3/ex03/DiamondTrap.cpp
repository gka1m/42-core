/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:46:58 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/18 16:39:22 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Diamond_clap_name"), FragTrap(), ScavTrap(), name("Diamond")
{
    hp = FragTrap::hp;
    energy = ScavTrap::energy;
    dmg = FragTrap::dmg;

    std::cout << "Default Diamond " << name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name)  
{
    hp = FragTrap::hp;
    energy = ScavTrap::energy;
    dmg = FragTrap::dmg;

    std::cout << "Diamond " << name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
    std::cout << "Diamond copy " << name << " constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
    }

    std::cout << "Diamond " << name << " assigned" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Bye Diamond!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

// void DiamondTrap::whoAmI()