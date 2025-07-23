/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:13 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/23 16:30:49 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* data;
        int size;

    public:
        Array() : data(NULL), size(0) {}
        Array(int n) : data(new T[n]), size(n) {}
        Array(const Array& other) : data(NULL), size(0) {}
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] data;
                size = other.size;
                data = new T[size];
                for (int i = 0; i < size; i++)
                    data[i] = other.data[i];
            }
            return *this;
        }
        ~Array()
        {
            delete[] data;
        }
};

#endif