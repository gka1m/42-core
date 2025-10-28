/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:01 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/27 15:04:13 by kagoh            ###   ########.fr       */
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
    std::srand(std::time(0)); // seed RNG for robotomy

    try 
    {
        // ----------------- Create bureaucrats -----------------
        Bureaucrat alice("Alice", 1);      // Very high rank
        Bureaucrat bob("Bob", 150);        // Lowest rank
        Bureaucrat charlie("Charlie", 70); // Mid-rank

        // ----------------- Create an intern -----------------
        Intern someIntern;

        std::cout << "\n--- Intern creates forms ---\n";
        AForm* shrub = someIntern.makeForm("shrub creation form", "home");
        AForm* robot = someIntern.makeForm("robotomy request form", "Bender");
        AForm* pardon = someIntern.makeForm("presidential pardon form", "Marvin");
        AForm* unknown = someIntern.makeForm("unknown form", "Target"); // Should fail

        // ----------------- Execute unsigned forms -----------------
        std::cout << "\n--- Trying to execute unsigned forms ---\n";
        try { if (shrub) shrub->execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { if (robot) robot->execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { if (pardon) pardon->execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

        // ----------------- Sign forms -----------------
        std::cout << "\n--- Signing forms ---\n";
        if (shrub) alice.signForm(*shrub);
        if (robot) charlie.signForm(*robot);
        if (pardon) bob.signForm(*pardon); // Should fail

        // ----------------- Execute forms -----------------
        std::cout << "\n--- Executing forms ---\n";
        try { if (shrub) shrub->execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { if (robot) robot->execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { if (pardon) pardon->execute(alice); } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

        // ----------------- Clean up dynamically allocated forms -----------------
        /* delete statements are necessary because Intern class just creates a new object on the heap and then 
        allocates a pointer to it; destructors are not called after the usage, therefore delete must be called manually */
        delete shrub;
        delete robot;
        delete pardon;
        delete unknown; // safe even if NULL
    } 
    catch (std::exception& e)
    {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}
