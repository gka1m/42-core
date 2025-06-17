/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:07:27 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/17 15:55:18 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("gkaim"), hp(10), energy(10), dmg(0)
{
    std::cout << "Default ClapTrap has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hp(10), energy(10), dmg(0)
{
    std::cout << "ClapTrap " << name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :  name(other.name), hp(other.hp), energy(other.dmg), dmg(other.dmg)
{
    std::cout << "Copy called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hp = other.hp;
        energy = other.energy;
        dmg = other.dmg;
    }
    std::cout << "Assignment operator called for " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Bye " << name << "!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, int hp, int energy, int dmg)
    : name(name), hp(hp), energy(energy), dmg(dmg)
{
    std::cout << "ClapTrap " << name << " has been custom-constructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hp <= 0 || energy <= 0)
    {
        std::cout << "No point attacking. " << name << " too shag or dead" << std::endl;
        return;
    }
    energy--;
    std::cout << name << " attacks " << target
    << ", causing " << dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp <= 0)
    {
        std::cout << name << "already ded" << std::endl;
        return;
    }
    hp -= amount;
    if (hp < 0)
        hp = 0;
    std::cout << name << " tanked " << amount << " damage.\n"
    << "Remaining HP: " << hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp <= 0 || energy <= 0)
    {
        std::cout << name << " cannot be repaired. No energy or dead" << std::endl;
        return;
    }
    energy--;
    hp += amount;
    
    std::cout << "Repaired " << amount << " health.\n"
    << "HP: " << hp << std::endl;
}

// getter fns
std::string ClapTrap::getName() const
{ 
    return name; 
}

int ClapTrap::getHP() const
{
    return hp; 
}

int ClapTrap::getEnergy() const
{
    return energy;
}

int ClapTrap::getDmg() const
{
    return dmg;
}
