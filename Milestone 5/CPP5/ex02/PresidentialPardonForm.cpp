/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:59:40 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/15 13:28:23 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pardon Form", 25, 5), target("Default")
{
    std::cout << "Deafult pardon requested" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Pardon Form", 25, 5), target(target)
{
    std::cout << "Pardon requested for " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), target(other.target)
{
    std::cout << "Copy of pardon requested" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    (void)other;
    std::cout << "Pardon has been assigned" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Don't commit any more crimes" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblerox."
    << std::endl;
}