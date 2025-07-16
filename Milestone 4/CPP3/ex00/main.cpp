/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:39:39 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/16 14:31:31 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
    ClapTrap a; // default
    ClapTrap b("BravBot"); // name-only
    ClapTrap c("TankBot", 150, 5, 42); // custom constructor
    ClapTrap aa(c);
    ClapTrap bb;
    bb = b;

    printStats(a, "Default ClapTrap");
    printStats(b, "Named ClapTrap");
    printStats(c, "Custom ClapTrap");
    printStats(aa, "Copy Claptrap");
    printStats(bb, "Assigned ClapTrap");

    std::cout << "\n=== Testing attack ===" << std::endl;
    b.attack("EvilBot");

    std::cout << "\n=== Testing takeDamage ===" << std::endl;
    b.takeDamage(4);
    b.takeDamage(20); // should test if HP drops below 0

    std::cout << "\n=== Testing beRepaired ===" << std::endl;
    b.beRepaired(10);

    std::cout << "\n=== Final Stats ===" << std::endl;
    printStats(b, "BravBot");
}