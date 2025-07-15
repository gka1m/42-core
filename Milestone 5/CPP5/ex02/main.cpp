/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:01 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/15 13:35:28 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        // Bureaucrats of different grades
        Bureaucrat alice("Alice", 1);     // Can do anything
        Bureaucrat bob("Bob", 45);        // Mid-level
        Bureaucrat carl("Carl", 150);     // Lowest level

        // Shrubbery Form Test
        {
            ShrubberyCreationForm shrub("home");
            std::cout << shrub << std::endl;
            alice.signForm(shrub);
            alice.execute(shrub);
        }

        std::cout << "-------------------------------" << std::endl;

        // Robotomy Form Test
        {
            RobotomyRequestForm robot("Bender");
            std::cout << robot << std::endl;
            bob.signForm(robot);

            for (int i = 0; i < 5; ++i) {
                try {
                    bob.executeForm(robot);  // Should work (bob is grade 45)
                } catch (const std::exception& e) {
                    std::cerr << "Execution error: " << e.what() << std::endl;
                }
            }
        }

        std::cout << "-------------------------------" << std::endl;

        // Presidential Pardon Form Test
        {
            PresidentialPardonForm pardon("Ford Prefect");
            std::cout << pardon << std::endl;

            try {
                bob.signForm(pardon);  // Should fail, grade too low
            } catch (const std::exception& e) {
                std::cerr << "Signing failed: " << e.what() << std::endl;
            }

            alice.signForm(pardon);       // Should succeed
            alice.executeForm(pardon);    // Should succeed
        }

        std::cout << "-------------------------------" << std::endl;

        // Test low-level bureaucrat with all forms
        {
            ShrubberyCreationForm shrub("garden");
            RobotomyRequestForm robot("Marvin");
            PresidentialPardonForm pardon("Arthur Dent");

            std::cout << shrub << std::endl;
            std::cout << robot << std::endl;
            std::cout << pardon << std::endl;

            carl.signForm(shrub);   // Should fail
            carl.executeForm(shrub); // Should fail
        }

    } catch (const std::exception& e) {
        std::cerr << "Fatal exception: " << e.what() << std::endl;
    }

    return 0;
}
