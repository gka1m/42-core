/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:01 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/27 13:24:55 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    std::cout << "--- Testing valid and invalid Form construction ---" << std::endl;
    try 
    {
        Form validForm("TopSecret", 50, 25);
        std::cout << validForm << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Error creating validForm: " << e.what() << std::endl;
    }

    try 
    {
        Form tooHigh("IllegalForm", 0, 100); // should throw
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (too high grade): " << e.what() << std::endl;
    }

    try 
    {
        Form tooLow("BottomFeeder", 151, 150); // should throw
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (too low grade): " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Testing Bureaucrats and Form signing ---" << std::endl;
    try 
    {
        Bureaucrat bob("Bob", 45);
        Bureaucrat joe("Joe", 100);

        Form permit("PermitForm", 50, 20);

        std::cout << bob << std::endl;
        std::cout << joe << std::endl;
        std::cout << permit << std::endl << std::endl;

        bob.signForm(permit); // should succeed
        std::cout << permit << std::endl;

        joe.signForm(permit); // already signed, but let's see what happens
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Signing error: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Testing failure to sign due to low grade ---" << std::endl;
    try 
    {
        Bureaucrat intern("Intern", 150);
        Form securityForm("SecurityAccess", 100, 50);

        intern.signForm(securityForm); // should fail
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught while signing: " << e.what() << std::endl;
    }
    
    /* outputs for catch messages may appear after destructor messages
       due to code going our of the scope of the try block before
       printing the error message */
    std::cout << std::endl << "--- Testing grade increment/decrement boundaries ---" << std::endl;
    try 
    {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);

        std::cout << high << std::endl;
        std::cout << low << std::endl;

        std::cout << "Trying to increment High beyond 1..." << std::endl;
        high.gradeUp(); // should throw
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (increment error): " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat low("Low", 150);
        std::cout << "Trying to decrement Low beyond 150..." << std::endl;
        low.gradeDown(); // should throw
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (decrement error): " << e.what() << std::endl;
    }

    return 0;
}
