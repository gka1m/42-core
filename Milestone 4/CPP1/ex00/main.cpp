/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:21:35 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/11 12:37:16 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie z("Foo");
    z.announce();

    Zombie* zz = newZombie("Fred");
    zz->announce();
    delete zz;

    randomChump("gkaim");
    
    return 0;
}