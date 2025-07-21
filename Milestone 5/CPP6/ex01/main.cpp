/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:18:31 by gkaim             #+#    #+#             */
/*   Updated: 2025/07/21 16:18:57 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data original;
    original.id = 123;
    original.name = "Test";

    std::cout << "Original Data pointer: " << &original << std::endl;
    std::cout << "Original Data id: " << original.id << ", name: " << original.name << std::endl;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&original);

    // Deserialize it back
    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Recovered Data pointer: " << recovered << std::endl;
    std::cout << "Recovered Data id: " << recovered->id << ", name: " << recovered->name << std::endl;

    // Check if the pointers match
    if (recovered == &original)
        std::cout << "✅ Success: Recovered pointer matches original" << std::endl;
    else
        std::cout << "❌ Failure: Recovered pointer does NOT match original" << std::endl;

    return 0;
}