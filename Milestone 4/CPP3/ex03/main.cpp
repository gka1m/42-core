/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:39:39 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/17 14:05:04 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Constructing FragTrap ===" << std::endl;
    FragTrap frag1("Fragger");

    std::cout << "\n=== Copy Constructing FragTrap ===" << std::endl;
    FragTrap frag2(frag1);

    std::cout << "\n=== Assigning FragTrap ===" << std::endl;
    FragTrap frag3;
    frag3 = frag1;

    std::cout << "\n=== Attack Test ===" << std::endl;
    frag1.attack("target A");

    std::cout << "\n=== High Fives Test ===" << std::endl;
    frag1.highFivesGuys();

    std::cout << "\n=== Energy Drain Test ===" << std::endl;
    for (int i = 0; i < 105; ++i) {
        frag1.attack("dummy");
    }

    std::cout << "\n=== Destruction Scope ===" << std::endl;
    {
        FragTrap tempFrag("ScopedFrag");
        tempFrag.attack("scoped target");
        tempFrag.highFivesGuys();
    } // Destructor should trigger here

    std::cout << "\n=== Done Testing ===" << std::endl;
    return 0;
}