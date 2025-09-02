/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:21:18 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/02 15:54:48 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc <filename>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    if (!btc.loadData(av[1]))
        return 1;
    btc.convertFile(av[1], "input.txt");
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Error: cannot open input file";
        return 1;
    }
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line))
    {
        std::string::size_type sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input at " << line << std::endl;
            continue; 
        }
        std::string date = line.substr(0, sep);
        std::string valueString = line.substr(sep + 3);
        if (!btc.checkDate(date))
        {
            std::cerr << "Error: bad date format at " << line << std::endl;
            continue; 
        }
        if (!btc.checkValue(valueString))
        {
            std::cerr << "Error: bad value at " << line << std::endl;
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