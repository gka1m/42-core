/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:55:33 by gkaim             #+#    #+#             */
/*   Updated: 2025/07/21 15:33:59 by gkaim            ###   ########.fr       */
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

bool isPseudoLiteral(const std::string& literal)
{
    return literal == "nanf" || literal == "nan" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff";
}

bool isFloatSuffix(const std::string& literal)
{
    return (!literal.empty() && literal[literal.size() - 1] == 'f');
}

void ScalarConverter::convert(const std::string& literal)
{
    char charVal;
    int intVal;
    float floatVal = 0.0f;
    double doubleVal = 0.0;

    // handling of character conversion
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        charVal = literal[0];
        intVal = static_cast<int>(charVal);
        floatVal = static_cast<float>(charVal);
        doubleVal = static_cast<double>(charVal);
    }
    // pseudo literals
    else if (isPseudoLiteral(literal))
    {
        charVal = 0;
        intVal = 0;
        if (literal == "nan" || literal == "nanf")
        {
            floatVal = NAN;
            doubleVal = NAN;
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            floatVal = INFINITY;
            doubleVal = INFINITY;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            floatVal = -INFINITY;
            doubleVal = -INFINITY;
        }
    }

    // numeric values
    else
    {
        char *end = NULL;
        errno = 0;
        doubleVal = std::strtod(literal.c_str(), &end);

        if (errno || (end == literal.c_str()) || (end != literal.c_str() + literal.length() && *end != 'f'))
        {
            std::cout << "Invalid input: " << literal << std::endl;
            return;
        }
        floatVal = static_cast<float>(doubleVal);
        intVal = static_cast<int>(doubleVal);
        charVal = static_cast<char>(doubleVal);
    }

    // print char
    std::cout << "Printed char: ";
    if (isPseudoLiteral(literal) || doubleVal < 0 || doubleVal > 127 || std::isnan(doubleVal))
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(charVal))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << charVal << "'" << std::endl;

    // print int
    std::cout << "Printed int: ";
    if (isPseudoLiteral(literal) || doubleVal > INT_MAX || doubleVal < INT_MIN || std::isnan(doubleVal))
        std::cout << "impossible" << std::endl;
    else
        std::cout << intVal << std::endl;

    // print float
    std::cout << "Printed float: ";
    std::cout << std::fixed << std::setprecision(1);
    if (isPseudoLiteral(literal))
    {
        if (literal == "nan" || literal == "nanf")
            std::cout << "nanf" << std::endl;
        else if (literal == "+inf" || literal == "+inff")
            std::cout << "+inff" << std::endl;
        else if (literal == "-inf" || literal == "-inff")
            std::cout << "-inff" << std::endl;
    }
    else
        std::cout << floatVal << "f" << std::endl;

    // print double
    std::cout << "Printed double: ";
    if (isPseudoLiteral(literal))
    {
        if (literal == "nan" || literal == "nanf")
            std::cout << "nan" << std::endl;
        else if (literal == "+inf" || literal == "+inff")
            std::cout << "+inf" << std::endl;
        else if (literal == "-inf" || literal == "-inff")
            std::cout << "-inf" << std::endl;
    }
    else
        std::cout << doubleVal << std::endl;

}