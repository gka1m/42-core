/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:29:38 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/04 15:21:23 by gkaim            ###   ########.fr       */
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

/* note: commented out the attribute line as both are usable in c++98; can use either one*/
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
            /* fall through */
            // __attribute__((fallthrough));

        case 1:
            harl.complain("INFO");
            /* fall through */
            // __attribute__((fallthrough));

        case 2:
            harl.complain("WARNING");
            /* fall through */
            // __attribute__((fallthrough));

        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "Anyhow complaining" << std::endl; 
    }
    return 0;
}