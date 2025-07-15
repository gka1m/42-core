/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:40:45 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/15 16:28:27 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        // Orthodox Canonical Form constructors + destructor
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // getter functions
        const std::string& getName() const;
        int getGrade() const;

        // increment and decrement grade functions
        void gradeUp(); // grade -1
        void gradeDown(); // grade +1

        void signForm(const AForm& f);

        /* exception classes */
        class GradeTooHighException : public std::exception
        {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu);

#endif