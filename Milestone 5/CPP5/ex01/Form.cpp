/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:05:49 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/10 10:44:26 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
    std::cout << "Default form created" << std::endl;
}

Form::Form(const std::string& name, int gsign, int gexec) : name(name), isSigned(false), gradeToSign(gsign), gradeToExec(gexec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "Parameterized form created" << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(false), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "Copy form created" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form shredded" << std::endl;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExec() const
{
    return gradeToExec;
}

void Form::beSigned(const Bureaucrat& bu)
{
    if (bu.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high, form cannot be signed";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low, form cannot be signed";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName() << "\nsigned: " << f.getSigned()
    << "\nGrade to sign: " << f.getGradeToSign()
    << "\nGrade to execute: " << f.getGradeToExec();
    return os;
}