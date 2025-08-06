/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:39:39 by kagoh             #+#    #+#             */
/*   Updated: 2025/08/06 15:54:56 by kagoh            ###   ########.fr       */
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
    std::cout << "\n=== [1] Default Construction ===" << std::endl;
    DiamondTrap dt1;
    printStats(dt1, "Default");

    std::cout << "\n=== [2] Parameterized Construction ===" << std::endl;
    DiamondTrap dt2("DiaBot");
    printStats(dt2, "Named");

    std::cout << "\n=== [3] Basic Functionality ===" << std::endl;
    dt2.attack("Mutant");
    dt2.takeDamage(30);
    dt2.beRepaired(20);
    dt2.whoAmI();
    printStats(dt2, "After Basic Actions");

    std::cout << "\n=== [4] Energy Exhaustion Stress Test ===" << std::endl;
    for (int i = 0; i < 101; ++i)
        dt2.attack("Dummy");
    printStats(dt2, "After Energy Depletion");

    std::cout << "\n=== [5] HP Edge Case Test ===" << std::endl;
    dt2.takeDamage(200); // reduce to 0
    dt2.attack("Zombie"); // should fail
    dt2.beRepaired(10);   // should fail
    printStats(dt2, "After Fatal Damage");

    std::cout << "\n=== [6] Copy Constructor Test ===" << std::endl;
    DiamondTrap dt3(dt2); // should invoke copy constructor
    printStats(dt3, "Copy Constructed");

    std::cout << "\n=== [7] Copy Assignment Operator Test ===" << std::endl;
    DiamondTrap dt4;
    dt4 = dt1; // should invoke copy assignment
    printStats(dt4, "Assigned From Default");

    // std::cout << "\n=== [8] Stacked Destruction Test ===" << std::endl;
    // {
    //     DiamondTrap temp1("StackA");
    //     DiamondTrap temp2("StackB");
    //     DiamondTrap temp3("StackC");
    //     std::cout << "Exiting local scope..." << std::endl;
    // }

    std::cout << "=== Polymorphic Deletion Test ===" << std::endl;
    ClapTrap* polyDia = new DiamondTrap("PolyDia");
    // printStats(*polyScav, "Polymorphic ScavTrap");

    delete polyDia; // This should call ScavTrap's and ClapTrap's destructors

    std::cout << "\n=== End of main() ===" << std::endl;
    return 0;
}