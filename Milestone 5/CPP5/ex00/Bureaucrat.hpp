/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:40:45 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/27 12:23:14 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

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
        // for use in main function
        const std::string& getName() const;
        int getGrade() const;

        // increment and decrement grade functions
        void gradeUp(); // grade -1
        void gradeDown(); // grade +1

        /* exception classes */
        // the throw keyword functions the same as the noexcept keyword in c++11
        // no exceptions will be thrown
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

// overload operator for Bureaucrat defined class
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu);

#endif