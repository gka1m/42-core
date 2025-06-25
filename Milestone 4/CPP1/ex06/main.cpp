/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:29:38 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/25 14:13:13 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int getLog(const std::string& level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

int main(int ac, char **av)
{
    Harl harl;
    
    if (ac != 2)
    {
        std::cerr << "Usage: ./harlFilter <command>" << std::endl;
        return 1;
    }
    
    std::string input = av[1];
    int level = getLog(input);

    switch(level)
    {
        case 0:
            harl.complain("DEBUG");
            // [[fallthrough]];
        case 1:
            harl.complain("INFO");
            // [[fallthrough]];
        case 2:
            harl.complain("WARNING");
            // [[fallthrough]];
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "Anyhow complaining" << std::endl; 
    }
    return 0;
}