/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:47:04 by kagoh             #+#    #+#             */
/*   Updated: 2025/12/10 12:23:16 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const& max(T& a, T& b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <typename T>
T const& min(T& a, T& b)
{
    if (a < b)
        return a;
    else
        return b;
}

#endif