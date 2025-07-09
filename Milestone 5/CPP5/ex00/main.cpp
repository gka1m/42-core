/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:01 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/09 15:21:51 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "== Constructing Bureaucrats ==\n";
    try 
    {
        Bureaucrat a("Alice", 1); // Valid
        Bureaucrat b("Bob", 150); // Valid
        Bureaucrat c("Charlie", 75); // Valid
        std::cout << a << "\n" << b << "\n" << c << "\n";
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Exception during construction: " << e.what() << std::endl;
    }

    std::cout << "\n== Invalid Construction (Too High) ==\n";
    try 
    {
        Bureaucrat d("Dave", 0); // Invalid
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n== Invalid Construction (Too Low) ==\n";
    try 
    {
        Bureaucrat e("Eve", 151); // Invalid
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n== Increment and Decrement Tests ==\n";
    try 
    {
        Bureaucrat f("Frank", 2);
        std::cout << f << std::endl;
        f.gradeUp(); // should succeed
        std::cout << "After increment: " << f << std::endl;
        f.gradeUp(); // should throw
        std::cout << "After second increment: " << f << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught during increment test: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat g("Grace", 149);
        std::cout << g << std::endl;
        g.gradeDown(); // should succeed
        std::cout << "After decrement: " << g << std::endl;
        g.gradeDown(); // should throw
        std::cout << "After second decrement: " << g << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Caught during decrement test: " << e.what() << std::endl;
    }

    std::cout << "\n== Copy and Assignment Test ==\n";
    try
    {
        Bureaucrat h("Henry", 50);
        Bureaucrat i = h; // Copy constructor
        std::cout << "Copy: " << i << std::endl;

        Bureaucrat j("Jack", 100);
        j = h; // Assignment operator
        std::cout << "After assignment: " << j << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Exception during copy/assignment: " << e.what() << std::endl;
    }

    return 0;
}