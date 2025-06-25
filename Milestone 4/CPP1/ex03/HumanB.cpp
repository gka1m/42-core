/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:07 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/25 13:18:03 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {};

void HumanB::attack() const
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else 
        std::cout << this->name << " has no weapons to attack with! " << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
    this->weapon = &newWeapon;
}