/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:16:19 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/25 12:27:23 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook() : total(0) {}

static bool validPhone(const std::string& str)
{
    if (str.empty())
        return false;
    
    std::size_t i = 0;
    if (str[0] == '+')
        i++;
    bool digits = false;
    for (; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
            digits = true;
        else if (str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == '-')
            continue;
        else
            return false;
    }
    return digits;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (input.empty())
        return;
    newContact.initFields("first", input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (input.empty())
        return;
    newContact.initFields("last", input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (input.empty())
        return;
    newContact.initFields("nick", input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    // if (input.empty())
    //     return;
    if (input.empty() || !validPhone(input))
    {
        std::cout << "Invalid phone number"
        << "Use digits, optional + for country code, spaces, dashes, parenthesis"
        << std::endl;
        return;
    }
    newContact.initFields("phone", input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (input.empty())
        return;
    newContact.initFields("secret", input);

    if (newContact.isEmpty())
    {
        std::cout << "Contact has empty fields. Please fill all fields. Contact not saved" << std::endl;
        return;
    }
    int index = total % 8;
    contacts[index] = newContact;
    total++;
    std::cout << "Contact saved at position " << index << ".\n";
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
    << std::setw(10) << "First Name" << "|"
    << std::setw(10) << "Last Name" << "|"
    << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------\n";
    
    int count = total < 8 ? total : 8;
    for (int i = 0; i < count; ++i) 
    {
        contacts[i].displaySummary(i);
    }
}

void PhoneBook::displayDetailed(int index) const
{
    int count = total < 8 ? total : 8;
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index \n";
        return;
    }
    contacts[index].displayFull();
}
