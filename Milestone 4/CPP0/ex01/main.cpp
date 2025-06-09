/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:50:13 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/09 15:00:51 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

int main(void)
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);
        
        if (std::cin.eof())
            break;
        if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
        {
            pb.displayContacts();
            std::cout << "Enter index for deets: ";
            std::string input;
            std::getline(std::cin, input);
            try
            {
                int index = std::stoi(input);
                pb.displayDetailed(index);
            }
            catch(...)
            {
                std::cout << "Invalid index \n";
            }
        }
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Invalid command \n";
    }
    return 0;
}