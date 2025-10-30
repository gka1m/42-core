/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:55:33 by gkaim             #+#    #+#             */
/*   Updated: 2025/10/30 13:45:14 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* OCF constructors + destructor
   will not appear in main (non-instantiable) as it is purely a utility class due to the presence of one static method convert */
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

/* Function checks whether the given string matches one of the pseudo literals defined by C++:
  - "nan", "nanf"
  - "+/-inf
  - "+/-inff" 
  The above represents special floating point values not corresponding to real finite numbers. Used to handle
  special cases for float/double conversion.
  
  Function returns true if string is a pseudo-literal, and false otherwise*/
bool isPseudoLiteral(const std::string& literal)
{
    return literal == "nanf" || literal == "nan" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff";
}

/* Function is used to detect if the string ends with the char 'f', indicating a float literal (e.g. 2.4f).
   Returns true if the last char  is a float literal, and false otherwise.*/
bool isFloatSuffix(const std::string& literal)
{
    return (!literal.empty() && literal[literal.size() - 1] == 'f');
}

/* Performs scalar type conversion on a given string and prints out the corresponding representations in the
   4 defined scalar types according to subject: 'char', 'int', 'float', 'double'
   Function makes use of static_cast to demonstrate explicit type conversion, which is safer than traditional C type casting
   Conversions are checked and intentional, ensuring that precision, truncation and overflow are handled properly */
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
    // pseudo literals (to handle overflow) and for cases where conversion is not possible
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

   /* std::strtod() to safely parse the
    string into a double value. It then performs several validation checks:
 
    - errno is checked to detect overflow or underflow conditions.
    - If no digits were parsed (end == literal.c_str()), the input is invalid.
    - If extra non-'f' characters remain after parsing, the input is invalid.
 
    This ensures that only valid numeric strings (e.g. "42", "4.2f", "-3.14")
    are converted, while malformed inputs like "42abc" or "nanx" are rejected
    with an "Invalid input" message. */
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
    std::cout << "char: ";
    if (isPseudoLiteral(literal) || doubleVal < 0 || doubleVal > 127 || std::isnan(doubleVal))
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(charVal))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << charVal << "'" << std::endl;

    // print int
    std::cout << "int: ";
    if (isPseudoLiteral(literal) || doubleVal > INT_MAX || doubleVal < INT_MIN || std::isnan(doubleVal))
        std::cout << "impossible" << std::endl;
    else
        std::cout << intVal << std::endl;

    // print float
    std::cout << "float: ";
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
    std::cout << "double: ";
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