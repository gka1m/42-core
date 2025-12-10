/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:54:42 by kagoh             #+#    #+#             */
/*   Updated: 2025/12/10 12:30:52 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

template <typename T, typename F>
void iter(T* arr, size_t len, F fn)
{
    for (size_t i = 0; i < len; i++)
        fn(arr[i]);
}

#endif