/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:44:55 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/01 11:27:03 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;

    public:
        /* OCF constructors + destructor */
        AForm();
        AForm(const std::string& name, int gsign, int gexec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        /* getter functions */
        const std::string& getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        
        /* be signed function */
        void beSigned(const Bureaucrat& bu);

        /* abstract function */
        virtual void execute(const Bureaucrat& executor) const = 0;
        
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
        class NotSignedException: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& af);

#endif
