/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:43:41 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/09 15:05:39 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

void Contact::initFields(const std::string& field, const std::string& value)
{
    if (field == "first")
        firstName = value;
    else if (field == "last")
        lastName = value;
    else if (field == "nick")
        nickname = value;
    else if (field == "phone")
        number = value;
    else if (field == "secret")
        darkestSecret = value;
}

std::string Contact:: getField(const std::string& field) const
{
    if (field == "first")
        return firstName;
    else if (field == "last")
        return lastName;
    else if (field == "nick")
        return nickname;
    else if (field == "phone")
        return number;
    else if (field == "secret")
        return darkestSecret;
    return "";
}

bool  Contact::isEmpty() const
{
    return (firstName.empty() || lastName.empty() || number.empty() || darkestSecret.empty() || nickname.empty());
}

void Contact::displaySummary(int index) const
{
    auto format = [](std::string str)
    {
        if (str.length() > 10)
            return (str.substr(0, 9) + ".");
        return str;
    };
    std::cout << std::setw(10) << index << "|"
    << std::setw(10) << format(firstName) << "|"
    << std::setw(10) << format(lastName) << "|"
    << std::setw(10) << format(nickname) << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << number << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}