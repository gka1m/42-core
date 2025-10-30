/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:49:50 by gkaim             #+#    #+#             */
/*   Updated: 2025/10/30 14:56:46 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer initialized" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
    std::cout << "Copy serializer initialized" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    std::cout << "Serializer assigned" << std::endl;
    return *this;
}

Serializer::~Serializer() {}

/* Converts a pointer to an unsigned integer using the function reinterpret_cast
   reinterprt_cast doesn't alter the bit pattern, but it just reinterprets the address
   of the pointer in a numeric form */
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

/* converts the integer back to a pointer by using reinterpret_cast
   restores the original pointer value and allows access to the same memory address */
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}