/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:58:15 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/24 16:37:33 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            std::cout << (char)std::toupper(av[i][j]);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}