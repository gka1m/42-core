/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:57:36 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/03 15:59:13 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void printCon(const T& cont, std::string& label)
{
    std::cout << label;
    for (size_t i = 0; i < cont.size(); i++)
        std::cout << cont[i] << " ";
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    
}