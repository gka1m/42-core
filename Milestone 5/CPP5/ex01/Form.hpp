/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:53:50 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/09 16:05:52 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>


class Form
{
    private:
        const std::string& name;
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
        

};

#endif
