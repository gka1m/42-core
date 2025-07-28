/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:43:43 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/28 16:10:20 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
    private:
        unsigned int maxSize;
        std::vector<int> numbers;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        
        template<typename Iterator>
        void rangeAdd(Iterator begin, Iterator end)
        {
            if (numbers.size() + std::distance(begin, end) > maxSize)
                throw std::overflow_error("Insufficient span space");

            numbers.insert(numbers.end(), begin, end);
        }
};

#endif