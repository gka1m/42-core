/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:18:07 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/24 16:45:40 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string firstName, lastName, nickname, number, darkestSecret;
    public:
        void initFields(const std::string& field, const std::string& value);
        std::string getField(const std::string& field) const;
        bool isEmpty() const;
        void displaySummary(int index) const;
        void displayFull() const;
        static std::string formatField(const std::string& str); // declared as static as it is a utility method
};
#endif