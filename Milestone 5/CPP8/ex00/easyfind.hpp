/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:34:59 by gkaim             #+#    #+#             */
/*   Updated: 2025/10/31 14:43:17 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYTFIND_HPP
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
