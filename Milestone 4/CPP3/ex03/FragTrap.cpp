/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:49:30 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/17 14:06:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    name = "Frag_gkaim";
    hp = 100;
    energy = 100;
    dmg =30;

    std::cout << "Default Frag " << name << " created" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
    this->name = name;
    hp = 100;
    energy = 100;
    dmg =30;
    
    std::cout << "Default Frag " << name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
    *this = other;
    
    std::cout << "Copy Frag " << name << " constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hp = other.hp;
        energy = other.energy;
        dmg = other.dmg;
    }

    std::cout << "Frag " << name << " assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Bye Fraggie!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (hp <= 0 || energy <= 0)
    {
        std::cout << name << " has no energy or dead" << std::endl;
        return;
    }
    energy--;
    std::cout << name << "frags " << target 
    << " brutally with " << dmg << " damage" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << name << " wants to bro out with a high five!" << std::endl;
}
