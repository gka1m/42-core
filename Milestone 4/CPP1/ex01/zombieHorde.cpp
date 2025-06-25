/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:47:38 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/25 13:09:07 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;

    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        std::ostringstream oss;
        oss << name << (i + 1);
        horde[i].setName(oss.str());
    }
    return horde;
}