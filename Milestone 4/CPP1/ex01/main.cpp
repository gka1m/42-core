/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:21:35 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/11 12:55:32 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int count = 5;
    Zombie *horde = zombieHorde(count, "Walker");

    if (!horde)
        return 1;
    for (int i = 0; i < count; i++)
        horde[i].announce();

    delete[] horde;
    return 0;
}