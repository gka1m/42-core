/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:05:58 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/17 13:22:07 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    name = "Scav_gkaim";
    hp = 100;
    energy = 50;
    dmg = 20;
    
    std::cout << " Default Scav " << name << " constructed" << std::endl;  
}

ScavTrap::ScavTrap(const std::string& name)
{
    this->name = name;
    hp = 100;
    energy = 50;
    dmg = 20;
    
    std::cout << "Scav " << name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    *this = other;
    
    std::cout << "Copy Scav " << name << " constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hp = other.hp;
        energy = other.energy;
        dmg = other.dmg;
    }

    std::cout << "Scav " << name << " assigned" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Bye Scavvie!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hp <= 0 || energy <= 0)
    {
        std::cout << name << " has no energy or dead" << std::endl;
        return;
    }
    energy--;
    std::cout << name << "attacks " << target << " brutally with " << dmg << " damage" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << name << " has entered Gate Keeper mode!" << std::endl;
}
