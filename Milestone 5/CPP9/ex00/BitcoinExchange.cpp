/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:06:38 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/29 16:26:35 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Constructed. Ready to analyze" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : btcPrices(other.btcPrices)
{
    std::cout << "Copied" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        btcPrices = other.btcPrices;
    }
    std::cout << "Assignment as been assigned" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Freed! Continue investing~~" << std::endl;
}

bool BitcoinExchange::loadData(const std::string& filename)
{
    if (filename.substr(filename.find_last_of('.') + 1) != "csv")
        std::cerr << "Only .csv files accepted" << std::endl;
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, value;

        if (!std::getline(ss, date, ',') || !std::getline(ss, value))
        {
            std::cerr << "Bad format in line: " << line << std::endl;
        }
        float val = (float)(std::atof(value.c_str()));
        btcPrices[date] = val;
    }
    return true;
}

