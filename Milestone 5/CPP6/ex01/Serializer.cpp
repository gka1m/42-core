/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:49:50 by gkaim             #+#    #+#             */
/*   Updated: 2025/07/21 16:05:10 by gkaim            ###   ########.fr       */
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

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}