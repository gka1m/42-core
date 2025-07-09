/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:58:08 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/09 15:43:22 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Default bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Constructor called; bureaucrat " << name << " constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat has left the building" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::gradeUp()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::gradeDown()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high. Cannot proceed";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
   return "Grade is too low. Cannot proceed";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu)
{
    os << bu.getName() << " , bureaucrat grade " << bu.getGrade();
    return os;
}
