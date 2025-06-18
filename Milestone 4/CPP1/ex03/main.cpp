/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:56:07 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/18 15:58:53 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        {
            Weapon club = Weapon("crude spiked club");
            HumanA bob("Bob", club);
            bob.attack();
            club.setType("some other type of club");
            bob.attack();
        }
        {
            Weapon club = Weapon("crude spiked club");
            HumanB jim("Jim");
            jim.attack();
            jim.setWeapon(club);
            // club.setType("some other type of club");
            jim.attack();
        }
        return 0;
    }
}
