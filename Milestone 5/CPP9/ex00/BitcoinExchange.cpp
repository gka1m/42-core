/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:06:38 by kagoh             #+#    #+#             */
/*   Updated: 2026/02/02 16:50:09 by kagoh            ###   ########.fr       */
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
    // Check if file is CSV
    if (filename.substr(filename.find_last_of('.') + 1) != "csv")
    {
        std::cerr << "Error: database must be a .csv file" << std::endl;
        return false;
    }
    
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Skip header line
    
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, value;

        if (!std::getline(ss, date, ',') || !std::getline(ss, value))
        {
            std::cerr << "Error: bad format in database line: " << line << std::endl;
            continue;
        }
        
        // Convert value to float
        float val = static_cast<float>(std::atof(value.c_str()));
        
        // Store in map (date -> exchange rate)
        // NO VALIDATION - exchange rates can be any value!
        btcPrices[date] = val;
    }
    
    return true;
}

bool BitcoinExchange::checkDate(const std::string& date)
{
    // Check format: YYYY-MM-DD (must be exactly 10 characters)
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    std::istringstream ss(date);
    char dash;

    ss >> year >> dash >> month >> dash >> day;
    
    // Check if parsing failed or values are out of range
    if (ss.fail() || year < 0 || month < 1 || month > 12 || day < 1)
        return false;
    int maxDays;
    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        maxDays = isLeapYear ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        maxDays = 30;
    }
    else
    {
        maxDays = 31;
    }
    if (day > maxDays)
        return false;
    return true;
}

bool BitcoinExchange::checkValue(const std::string& valueString)
{
    std::istringstream ss(valueString);
    float value;
    ss >> value;

    // Check if conversion failed or there's extra text
    if (ss.fail() || !ss.eof())
        return false;
    
    // THIS CHECK IS FOR USER INPUT VALUES ONLY
    // Value must be between 0 and 1000 (as per the subject)
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
    // lower_bound returns iterator to first element >= date
    std::map<std::string, float>::const_iterator it = btcPrices.lower_bound(date);

    // If exact match found, return it
    if (it != btcPrices.end() && it->first == date)
        return it->second;

    // If no exact match and we're at the beginning, no earlier date exists
    if (it == btcPrices.begin())
        return -1.0f;
    
    // Otherwise, go back one to get the closest earlier date
    --it;
    return it->second;
}
