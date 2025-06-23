/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:47:25 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/23 15:24:38 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = nullptr;
}

Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = nullptr;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    for (int j = 0; j < backpack.size(); ++j)
        delete backpack[j];
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* mat)
{
    if (!mat)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = mat;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        backpack.push_back(inventory[idx]);
        inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}