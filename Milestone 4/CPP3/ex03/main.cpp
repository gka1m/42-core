/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:39:39 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/18 17:08:29 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void printStats(const ClapTrap& ct, const std::string& label)
{
    std::cout << "---- " << label << " Stats ----" << std::endl;
    std::cout << "Name: " << ct.getName() << std::endl;
    std::cout << "HP: " << ct.getHP() << std::endl;
    std::cout << "Energy: " << ct.getEnergy() << std::endl;
    std::cout << "Damage: " << ct.getDmg() << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;
}

int main()
{
    std::cout << "=== Default DiamondTrap ===" << std::endl;
    DiamondTrap dt1;
    printStats(dt1, "Default Diamond");

    std::cout << "=== Named DiamondTrap ===" << std::endl;
    DiamondTrap dt2("DiaBot");
    printStats(dt2, "Named Diamond");

    std::cout << "=== Performing Actions ===" << std::endl;
    dt2.attack("Enemy");
    dt2.takeDamage(40);
    dt2.beRepaired(25);
    dt2.whoAmI();
    printStats(dt2, "After Actions");

    std::cout << "=== Copy & Assignment Test ===" << std::endl;
    DiamondTrap dt3 = dt2; // Copy constructor
    printStats(dt3, "Copied Diamond");

    DiamondTrap dt4;
    dt4 = dt1; // Assignment
    printStats(dt4, "Assigned Diamond");

    return 0;
}