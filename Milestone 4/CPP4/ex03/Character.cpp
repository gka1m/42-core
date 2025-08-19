/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:47:25 by kagoh             #+#    #+#             */
/*   Updated: 2025/08/19 09:45:21 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name) : name(name), backpackSize(0)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    for (int i = 0; i < 4; ++i)
        backpack[i] = NULL;
}

Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
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
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    for (int j = 0; j < backpackSize; ++j)
        delete backpack[j];
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* mat)
{
    if (!mat)
    {
        std::cout << "[equip] Tried to equip NULL materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = mat;
            std::cout << "[equip] " << name << " equipped " 
                      << mat->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "[equip] Inventory full, could not equip " 
              << mat->getType() << std::endl;
    // delete mat;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        std::cout << "[unequip] " << name << " unequipped "
                  << inventory[idx]->getType() << " from slot " << idx
                  << " and moved to backpack" << std::endl;

        if (backpackSize < 100)
        {
            backpack[backpackSize++] = inventory[idx];
        }
        else
        {
            std::cout << "[unequip] Backpack full, dropping materia" << std::endl;
        }

        inventory[idx] = NULL;
    }
    else
    {
        std::cout << "[unequip] Invalid slot " << idx
                  << " or empty inventory slot" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        std::cout << "[use] " << name << " uses " 
                  << inventory[idx]->getType() << " on " 
                  << target.getName() << std::endl;
        inventory[idx]->use(target);
    }
    else
    {
        std::cout << "[use] " << name << " tried to use slot " << idx 
                  << " but it's empty" << std::endl;
    }
}

AMateria* Character::getFromBackpack(int idx)
{
    if (idx >= 0 && idx < backpackSize && backpack[idx])
        return backpack[idx];
    return NULL;
}