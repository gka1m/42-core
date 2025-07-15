/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:39:14 by gkaim             #+#    #+#             */
/*   Updated: 2025/07/15 12:50:16 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
    std::cout << "Default shrub requested" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
    std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    (void)other;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrub has been trimmed" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw AForm::GradeTooLowException();
    
    std::ofstream ofs(target + "_shrub");
    if (!ofs.is_open())
    {
        std::cerr << "Error opening file " << target + "_shrub"
        << std::endl;
        return;
    }
    ofs << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\\n";
    ofs.close();
}
