/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:43:17 by gkaim             #+#    #+#             */
/*   Updated: 2025/10/30 15:02:49 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

/*  contains these 2 fields due to the following reasons:
    1. to make it non empty and to represent different data types: 1 stored in memory (int)
    and a class type (std::string) for dynamic memory -> proves that the serializer should work
    regadless of data type
    2. to demonstrate that the memory address remains the same before and after serialization */
struct Data
{
    int id;
    std::string name;
};

#endif