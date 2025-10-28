/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:01 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/27 14:56:33 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main() 
{
    std::srand(std::time(0)); // seed RNG for robotomy

    try 
    {
        Bureaucrat alice("Alice", 1);      // Very high rank
        Bureaucrat bob("Bob", 150);        // Lowest rank
        Bureaucrat charlie("Charlie", 70); // Mid-rank

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n--- Trying to execute unsigned forms ---\n";
        try { shrub.execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { robot.execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { pardon.execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

        std::cout << "\n--- Signing forms ---\n";
        alice.signForm(shrub);
        charlie.signForm(robot);
        bob.signForm(pardon); // Should fail

        std::cout << "\n--- Executing forms ---\n";
        try { shrub.execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { robot.execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { pardon.execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

        // std::cout << "\n--- Stress: Bob tries to do everything ---\n";
        // try { bob.signForm(shrub); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        // try { shrub.execute(bob); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        // try { robot.execute(bob); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        // try { pardon.execute(bob); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    } 
    catch (std::exception& e)
    {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}