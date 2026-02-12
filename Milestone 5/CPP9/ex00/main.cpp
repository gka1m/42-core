/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:21:18 by kagoh             #+#    #+#             */
/*   Updated: 2026/02/02 16:53:07 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    // Load the DATABASE (data.csv)
    if (!btc.loadData("data.csv"))
        return 1;
    
    // Open the USER INPUT FILE (passed as argument)
    std::ifstream input(av[1]);
    if (!input)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line))
    {
        std::string::size_type sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue; 
        }
        std::string date = line.substr(0, sep);
        std::string valueString = line.substr(sep + 3);
        if (!btc.checkDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue; 
        }
        if (!btc.checkValue(valueString))
        {
            float val = btc.toFlt(valueString);
            if (val < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (val > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        float value = btc.toFlt(valueString);
        float rate = btc.getRate(date);

        if (rate < 0)
        {
            std::cerr << "Error: no exchange rate available for " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
    return 0;
}