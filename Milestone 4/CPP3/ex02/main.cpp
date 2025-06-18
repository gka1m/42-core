/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:39:39 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/18 16:10:33 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void printStats(const ClapTrap& ct, const std::string& label)
{
    std::cout << "---- " << label << " Stats ----" << std::endl;
    std::cout << "Name: " << ct.getName() << std::endl;
    std::cout << "HP: " << ct.getHP() << std::endl;
    std::cout << "Energy: " << ct.getEnergy() << std::endl;
    std::cout << "Damage: " << ct.getDmg() << std::endl;
    std::cout << "------------------------\n" << std::endl;
}

int main(void) 
{
    std::cout << "=== Constructing Default FragTrap ===" << std::endl;
    FragTrap defaultFrag;
    printStats(defaultFrag, "Default FragTrap");

    std::cout << "=== Constructing Named FragTrap ===" << std::endl;
    FragTrap ft("FR4G-TP");
    printStats(ft, "Initial FragTrap");

    std::cout << "=== Basic Actions ===" << std::endl;
    ft.attack("Bandit");
    ft.takeDamage(35);
    ft.beRepaired(20);
    ft.highFivesGuys();
    printStats(ft, "After Basic Actions");

    std::cout << "=== Energy Exhaustion Stress Test ===" << std::endl;
    for (int i = 0; i < 101; ++i)
        ft.attack("Dummy");
    printStats(ft, "After Energy Exhaustion");

    std::cout << "=== Fatal Damage Test ===" << std::endl;
    ft.takeDamage(200);
    ft.beRepaired(10);  // Should fail
    ft.attack("Zombie");  // Should fail
    printStats(ft, "After Death");

    std::cout << "=== Destruction Order ===" << std::endl;
    return 0;
}
