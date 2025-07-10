/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:01 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/10 10:35:57 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    std::cout << "--- Testing valid and invalid Form construction ---\n";
    try 
    {
        Form validForm("TopSecret", 50, 25);
        std::cout << validForm << "\n";
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Error creating validForm: " << e.what() << "\n";
    }

    try 
    {
        Form tooHigh("IllegalForm", 0, 100); // should throw
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (too high grade): " << e.what() << "\n";
    }

    try 
    {
        Form tooLow("BottomFeeder", 151, 150); // should throw
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (too low grade): " << e.what() << "\n";
    }

    std::cout << "\n--- Testing Bureaucrats and Form signing ---\n";
    try 
    {
        Bureaucrat bob("Bob", 45);
        Bureaucrat joe("Joe", 100);

        Form permit("PermitForm", 50, 20);

        std::cout << bob << "\n";
        std::cout << joe << "\n";
        std::cout << permit << "\n\n";

        bob.signForm(permit); // should succeed
        std::cout << permit << "\n";

        joe.signForm(permit); // already signed, but let's see what happens
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Signing error: " << e.what() << "\n";
    }

    std::cout << "\n--- Testing failure to sign due to low grade ---\n";
    try 
    {
        Bureaucrat intern("Intern", 150);
        Form securityForm("SecurityAccess", 100, 50);

        intern.signForm(securityForm); // should fail
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught while signing: " << e.what() << "\n";
    }

    std::cout << "\n--- Testing grade increment/decrement boundaries ---\n";
    try 
    {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);

        std::cout << high << "\n";
        std::cout << low << "\n";

        std::cout << "Trying to increment High beyond 1...\n";
        high.gradeUp(); // should throw

    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (increment error): " << e.what() << "\n";
    }

    try 
    {
        Bureaucrat low("Low", 150);
        std::cout << "Trying to decrement Low beyond 150...\n";
        low.gradeDown(); // should throw
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught (decrement error): " << e.what() << "\n";
    }

    return 0;
}