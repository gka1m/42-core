/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:54:42 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/31 13:47:28 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

/* function takes in 3 parameters:
   - address of an array of type T
   - length of array
   - function to be called on every element in the array 
   and returns nothing.
   
   function serves to demonstrate the concept of templates with multiple type parameters and
   passing a function as a parameter */
template <typename T, typename F>
void iter(T& arr, size_t len, F fn)
{
    for (size_t i = 0; i < len; i++)
        fn(arr[i]);
}

#endif