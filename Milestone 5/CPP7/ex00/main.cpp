/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:52:19 by kagoh             #+#    #+#             */
/*   Updated: 2025/12/10 12:24:26 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) 
{
    int a = 2;
    int b = 3;
    int e = 2;
    std::cout << "max( a, e ) = " << ::max( a, e ) << std::endl;
    std::cout << "min( a, e ) = " << ::min( a, e ) << std::endl;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}