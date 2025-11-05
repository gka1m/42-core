/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:47:04 by kagoh             #+#    #+#             */
/*   Updated: 2025/11/05 12:32:46 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

/* - function swaps out two variables of the same type with a temp variable
   - since both a and b are references, changes in the fn will affect the original variables 
   - works for any type T*/
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

/* - function returns the greater value of the two types
   - return value is a const to avoid unnecessary copying
   - if both a and b are equal, return the second one 
   - works for any typ T that supports the > operator */
template <typename T>
T const& max(T& a, T& b)
{
    if (a > b)
        return a;
    else
        return b;
}

/* - function returns the smaller value of the two types
   - return value is a const to avoid unnecessary copying
   - if both a and b are equal, return the second one 
   - works for any typ T that supports the > operator */
template <typename T>
T const& min(T& a, T& b)
{
    if (a < b)
        return a;
    else
        return b;
}

#endif