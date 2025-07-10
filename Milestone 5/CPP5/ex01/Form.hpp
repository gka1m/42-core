/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:53:50 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/10 10:45:51 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
// #include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;

    public:
        /* OCF constructors + destructor */
        Form();
        Form(const std::string& name, int gsign, int gexec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        /* getter functions */
        const std::string& getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        
        /* be signed function */
        void beSigned(const Bureaucrat& bu);
        
        /* exception classes */
        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
