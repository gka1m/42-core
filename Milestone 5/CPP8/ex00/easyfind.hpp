/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:34:59 by gkaim             #+#    #+#             */
/*   Updated: 2026/01/06 12:08:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& container, int value);
// typename T::iterator easyfind(T& container, int value)
// {
//     typename T::iterator it = std::find(container.begin(), container.end(), value);
//     if (it == container.end())
//     {
//         throw std::runtime_error("Value not found in container");
//     }
//     return it;
// }

#include "easyfind.tpp"
#endif
