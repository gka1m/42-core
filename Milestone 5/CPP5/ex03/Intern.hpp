/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:45:10 by gkaim             #+#    #+#             */
/*   Updated: 2025/07/18 14:14:29 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Intern
{   
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target);
};

AForm* createShrubbery(const std::string& target);
AForm* createRobotomy(const std::string& target);
AForm* createPresidential(const std::string& target);

#endif