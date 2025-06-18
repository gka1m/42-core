/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:39:39 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/18 16:10:46 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void printStats(const ClapTrap& ct, const std::string& label)
{
    std::cout << "---- " << label << " Stats ----" << std::endl;
    std::cout << "Name: " << ct.getName() << std::endl;
    std::cout << "HP: " << ct.getHP() << std::endl;
    std::cout << "Energy: " << ct.getEnergy() << std::endl;
    std::cout << "Damage: " << ct.getDmg() << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;
}

int main(void) 
{
    std::cout << "=== Constructing Default ScavTrap ===" << std::endl;
    ScavTrap defaultScav;  // <-- uses default constructor
    printStats(defaultScav, "Default ScavTrap");
    
    std::cout << "=== Constructing ScavTrap ===" << std::endl;
    ScavTrap st("SC4V-TP");
    printStats(st, "Initial ScavTrap");

    std::cout << "=== Basic Actions ===" << std::endl;
    st.attack("Enemy2");
    st.takeDamage(20);
    st.beRepaired(10);
    st.guardGate();
    printStats(st, "After Basic Actions");

    std::cout << "=== Energy Exhaustion Stress Test ===" << std::endl;
    for (int i = 0; i < 51; ++i)
        st.attack("Dummy");
    printStats(st, "After Exhaustion");

    std::cout << "=== Fatal Damage Test ===" << std::endl;
    st.takeDamage(150);
    st.beRepaired(5); // Should fail
    st.attack("Mutant"); // Should fail
    printStats(st, "After Death");

    return 0;
}

