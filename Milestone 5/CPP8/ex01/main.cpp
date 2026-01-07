/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:03:07 by kagoh             #+#    #+#             */
/*   Updated: 2026/01/06 12:27:18 by kagoh            ###   ########.fr       */
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

        std::vector<int> values;
        values.reserve(N);

        std::srand(std::time(NULL));
        for (unsigned int i = 0; i < N; i++)
        {
            values.push_back(std::rand());
        }

        // ONE single call instead of 10,000 addNumber() calls
        bigSpan.rangeAdd(values.begin(), values.end());

        std::cout << "\nRangeAdd Span Test:" << std::endl;
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

    // === RANGE ADD OVERFLOW TEST ===
    try
    {
        Span sp2(3);
        std::vector<int> tooMany;
        tooMany.push_back(1);
        tooMany.push_back(2);
        tooMany.push_back(3);
        tooMany.push_back(4);

        sp2.rangeAdd(tooMany.begin(), tooMany.end());
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected rangeAdd error: " << e.what() << std::endl;
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