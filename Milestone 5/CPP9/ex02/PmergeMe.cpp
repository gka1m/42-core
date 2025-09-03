/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:54:56 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/03 12:24:33 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe constrructed" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) : v(other.v), dq(other.dq)
{
    std::cout << "PmergeMe copied" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        v = other.v;
        dq = other.dq;
    }
    std::cout << "PmergeMe assigned" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe destroyed" << std::endl;
}

bool PmergeMe(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    long val = std::atol(str.c_str());
    return val > 0;
}

