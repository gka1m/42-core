/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:44:50 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/11 15:35:13 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
    std::cout << "Default abstract form created!" << std::endl;
}

AForm::AForm(const std::string& name, int gsign, int gexec) : name(name), isSigned(false), gradeToSign(gsign), gradeToExec(gexec)
{
    if (gsign < 1 || gexec < 1)
        throw GradeTooHighException();
    if (gsign > 150 || gexec > 150)
        throw GradeTooLowException();
    std::cout << "Parameterized abstract form " << name << " created" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "Copy of abstract form created" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "Abstract form shredded" << std::endl;
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExec() const
{
    return gradeToExec;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm exception: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm exception: grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm exception: form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& af)
{
    os << "Aform " << af.getName()
        << "\nsigned: " << af.getSigned()
        << "\nSigning grade: " << af.getGradeToSign()
        << "\nExecute grade: " << af.getGradeToExec();
    return os;
}