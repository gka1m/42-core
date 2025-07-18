/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:01 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/18 14:25:54 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    try 
    {
        std::cout << "=== Intern creates forms ===" << std::endl;
        Intern someIntern;

        AForm* shrub = someIntern.makeForm("shrub creation form", "Home");
        AForm* robot = someIntern.makeForm("robotomy request form", "Bender");
        AForm* pardon = someIntern.makeForm("presidential pardon form", "Rick");
        AForm* unknown = someIntern.makeForm("coffee request", "Kitchen"); // should fail

        std::cout << "\n=== Bureaucrats with different grades ===" << std::endl;
        Bureaucrat alice("Alice", 1);     // High grade (can do anything)
        Bureaucrat bob("Bob", 145);       // Just enough to sign shrubbery
        Bureaucrat charlie("Charlie", 45); // Can do robotomy
        Bureaucrat dave("Dave", 150);     // Too low for most tasks

        std::cout << "\n=== Trying to execute unsigned forms ===" << std::endl;
        try { shrub->execute(bob); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        try { robot->execute(charlie); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        try { pardon->execute(alice); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

        std::cout << "\n=== Signing and executing forms ===" << std::endl;

        // Bob signs Shrubbery (grade 145 needed)
        bob.signForm(*shrub);
        try { shrub->execute(bob); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

        // Charlie signs Robotomy
        charlie.signForm(*robot);

        // Execute Robotomy multiple times to observe randomness
        for (int i = 0; i < 10; i++)
        {
            std::cout << "[Attempt " << (i + 1) << "] ";
            try { robot->execute(charlie); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        }

        // Alice signs and executes Pardon
        alice.signForm(*pardon);
        try { pardon->execute(alice); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

        std::cout << "\n=== Re-signing already signed form ===" << std::endl;
        alice.signForm(*pardon); // should print message, no error

        std::cout << "\n=== Dave tries to sign and execute everything ===" << std::endl;
        dave.signForm(*shrub);
        try { shrub->execute(dave); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        dave.signForm(*robot);
        try { robot->execute(dave); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        dave.signForm(*pardon);
        try { pardon->execute(dave); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

        std::cout << "\n=== Clean-up ===" << std::endl;
        delete shrub;
        delete robot;
        delete pardon;
        delete unknown; // Safe to delete NULL
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}


