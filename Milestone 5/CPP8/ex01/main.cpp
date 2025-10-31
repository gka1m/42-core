/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:03:07 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/31 14:54:42 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() 
{
    try 
    {
        // === SMALL TEST ===
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Attempt to add beyond capacity
        try 
        {
            sp.addNumber(42);
        } 
        catch (const std::exception &e) 
        {
            std::cout << "Expected error: " << e.what() << std::endl;
        }

        // === LARGE TEST ===
        const unsigned int N = 10000;
        Span bigSpan(N);

        std::srand(std::time(NULL));
        for (unsigned int i = 0; i < N; i++) 
        {
            bigSpan.addNumber(std::rand());
        }

        std::cout << "\nLarge Span Test:" << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

        // === ERROR CASE TEST ===
        try 
        {
            Span empty(2);
            std::cout << empty.shortestSpan() << std::endl; // should throw
        } 
        catch (const std::exception &e) 
        {
            std::cout << "Expected error (empty): " << e.what() << std::endl;
        }

    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}

// // subject main
// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }