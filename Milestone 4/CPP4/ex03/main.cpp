/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:00:14 by kagoh             #+#    #+#             */
/*   Updated: 2025/08/19 09:43:22 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    // AMateria *ice = ;
    // AMateria *cure = ;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(1);

    // --------- TESTING SECTION ---------
    std::cout << "\n=== Testing Section ===" << std::endl;

    // Try using unequipped slots
    me->use(0, *bob);
    me->use(1, *bob);

    // Try equipping more than 4 materias
    AMateria* extra1 = src->createMateria("ice");
    AMateria* extra2 = src->createMateria("cure");
    AMateria* extra3 = src->createMateria("ice");
    AMateria* extra4 = src->createMateria("cure");
    AMateria* extra5 = src->createMateria("ice"); // should fail (inventory full)

    me->equip(extra1);
    me->equip(extra2);
    me->equip(extra3);
    me->equip(extra4);
    me->equip(extra5);  // will trigger "Inventory full" log
    delete extra5;

    // Use materias again
    for (int i = 0; i < 4; ++i)
        me->use(i, *bob);

    // Unequip one and re-equip another
    me->unequip(2);
    me->equip(src->createMateria("ice"));

    std::cout << "=== End of Testing ===\n" << std::endl;

    delete bob;
    delete me;
    delete src;
    // delete ice;
    // delete cure;

    return 0;
}