/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:29:59 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/11 15:46:06 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug(void)
{
    std::cout << "[DEBUG]\n"
    << "Debugging mode activated. Lai, leggo\n";
}

void Harl::info(void)
{
    std::cout << "[INFO]\n"
    << "Come. What you wanna know?\n";
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\n"
    << "I wong you first ah. Don't come and anyhow\n";
}

void Harl::error(void)
{
    std::cout << "[ERROR]\n"
    << "Come on brodee, you have an error. Mai tu liao and fix this!\n";
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
        
    }
    std::cerr << "This guy kpkb all" << std::endl;
}