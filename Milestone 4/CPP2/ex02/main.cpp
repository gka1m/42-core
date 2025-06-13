/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:23:20 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/13 15:32:38 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() 
{
    Fixed a(5.5f);
    Fixed b(10);
    Fixed c(5.5f);
    Fixed d(2);
    
    std::cout << "\n--- Comparison Operators ---\n";
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a >= c: " << (a >= c) << "\n";
    std::cout << "a <= c: " << (a <= c) << "\n";
    std::cout << "a == c: " << (a == c) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";

    std::cout << "\n--- Arithmetic Operators ---\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "b / a = " << (b / a) << "\n";

    std::cout << "\n--- Increment / Decrement Operators ---\n";
    Fixed x;
    std::cout << "Initial x: " << x << "\n";
    std::cout << "Pre-increment: " << ++x << "\n";
    std::cout << "Post-increment: " << x++ << "\n";
    std::cout << "After post-increment: " << x << "\n";
    std::cout << "Pre-decrement: " << --x << "\n";
    std::cout << "Post-decrement: " << x-- << "\n";
    std::cout << "After post-decrement: " << x << "\n";

    std::cout << "\n--- Static min / max Functions ---\n";
    Fixed e(3.3f);
    Fixed f(6.6f);
    const Fixed g(7.7f);
    const Fixed h(4.4f);

    std::cout << "min(e, f): " << Fixed::min(e, f) << "\n";
    std::cout << "max(e, f): " << Fixed::max(e, f) << "\n";
    std::cout << "min(g, h): " << Fixed::min(g, h) << "\n";
    std::cout << "max(g, h): " << Fixed::max(g, h) << "\n";

    return 0;
}

// int main( void ) 
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }