/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:42:31 by kagoh             #+#    #+#             */
/*   Updated: 2026/02/02 16:50:37 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> btcPrices;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool loadData(const std::string& filename);
        bool checkDate(const std::string& date);
        bool checkValue(const std::string& valueString);
        float toFlt(const std::string& valueString);
        
        float getRate(const std::string& date);
        // bool convertFile(const std::string& csvFile, const std::string& txtFile);
};

#endif