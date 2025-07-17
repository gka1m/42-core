/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:49:30 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/17 16:32:15 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("frag_default", 100, 100, 30)
{
    std::cout << "Default Frag created" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "Frag " << getName() << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Copy Frag " << getName() + "_copy" << " constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);  // Use base assignment operator

    std::cout << "Frag " << getName() + "_assigned" << " assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {}

void FragTrap::attack(const std::string& target)
{
    if (getHP() <= 0 || getEnergy() <= 0)
    {
        std::cout << getName() << " has no energy or dead" << std::endl;
        return;
    }
    energy--;
    std::cout << getName() << "frags " << target 
    << " brutally with " << getDmg() << " damage" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << getName() << " wants to bro out with a high five!" << std::endl;
}
