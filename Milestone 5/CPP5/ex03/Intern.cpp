/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:48:37 by gkaim             #+#    #+#             */
/*   Updated: 2025/10/27 15:04:49 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
    std::cout << "Intern has been summoned" << std::endl;
}

Intern::Intern(const Intern& other)
{
    *this = other;
    std::cout << "Twin of intern has been summoned" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern has been assigned an identity" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern dismissed" << std::endl;
}

AForm* createShrubbery(const std::string& target) 
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string types[3] = {
        "shrub creation form",
        "robotomy request form",
        "presidential pardon form",
    };

    AForm* (*formCreators[3])(const std::string&) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (name == types[i])
        {
            std::cout << "Intern drafts out " << name << std::endl;
            return formCreators[i](target);
        }
    }
    std::cerr << "Intern couldn't find template for " << name << std::endl;
    return NULL;
}