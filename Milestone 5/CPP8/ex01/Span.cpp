/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:04:21 by kagoh             #+#    #+#             */
/*   Updated: 2026/01/06 12:13:21 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N)
{
    // std::cout << "Span constructed with " << N << " numbers" << std::endl;
}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    // std::cout << "Span assigned" << std::endl;
    return *this;
}

Span::~Span()
{
    // std::cout << "Span freed" << std::endl;
}

void Span::addNumber(int num)
{
    if (numbers.size() >= maxSize)
    {
        throw std::overflow_error("Cannot add more numbers: span full");
    }
    numbers.push_back(num);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find span");
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; i++)
    {
        int diff = std::abs(sorted[i] - sorted[i + 1]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find span");
    
    int smallest = *std::min_element(numbers.begin(), numbers.end());
    int largest = *std::max_element(numbers.begin(), numbers.end());
    
    return largest - smallest;
}
