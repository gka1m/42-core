/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:40:51 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/27 14:45:30 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("Default")
{
    std::cout << "Default Robotomy requested" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", 72, 45), target(target)
{
    std::cout << "Robotomy requested for " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
    std::cout << "Copy of robotomy request called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void)other;
    std::cout << "Robotomy operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Bot has been scrapped" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw AForm::GradeTooLowException();

    std::cout << "*Drilling noises*..." << std::endl;

    if (std::rand() % 2)
        std::cout << target << " successfully robotomized!" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}