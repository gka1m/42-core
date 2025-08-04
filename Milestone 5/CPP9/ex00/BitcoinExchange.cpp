/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:06:38 by kagoh             #+#    #+#             */
/*   Updated: 2025/08/01 10:53:42 by kagoh            ###   ########.fr       */
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

bool BitcoinExchange::checkDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    std::istringstream ss(date);
    char dash;

    ss >> year >> dash >> month >> dash >> day;
    if (ss.fail() || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::checkValue(const std::string& valueString)
{
    std::istringstream ss(valueString);
    float value;
    ss >> value;

    if (ss.fail() || !ss.eof())
        return false;
    
    return value >= 0.0f && value <= 1000.0f;
}

float BitcoinExchange::toFlt(const std::string& valueString)
{
    std::istringstream ss(valueString);
    float value;
    ss >> value;
    return value;
}

float BitcoinExchange::getRate(const std::string& date)
{
    std::map<std::string, float>::const_iterator it = btcPrices.lower_bound(date);

    if (it != btcPrices.end() && it->first == date)
        return it->second;

    if (it == btcPrices.begin())
        return -1.0f;
    
    --it;
    return it->second;
}