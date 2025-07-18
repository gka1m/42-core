/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:55:33 by gkaim             #+#    #+#             */
/*   Updated: 2025/07/18 15:10:54 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Converter initialized" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    std::cout << "Copy converter initialized" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    std::cout << "Converter assigned" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Converter decommissioned" << std::endl;
}

void ScalarConverter::convert(std::string& literal)
{

}