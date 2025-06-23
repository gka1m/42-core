/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:41:45 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/23 15:21:44 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <vector>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        std::vector<AMateria*> backpack;
    
    public:
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        std::string const& getName() const;
        void equip(AMateria* mat);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
