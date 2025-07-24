/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:19:13 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/24 13:41:10 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* data;
        unsigned int _size;

    public:
        Array() : data(NULL), _size(0) {}
        Array(unsigned int n) : data(new T[n]), _size(n) {}
        Array(const Array& other) : data(NULL), _size(0) 
        {
            *this = other;
        }
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] data;
                _size = other._size;
                data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    data[i] = other.data[i];
            }
            return *this;
        }
        ~Array()
        {
            delete[] data;
        }
        
        // subscript operator
        T& operator[](unsigned int idx)
        {
            if (idx >= _size)
                throw std::out_of_range("Index is out of bounds");
            return data[idx];
        }
        
        // const subscript operator (overloading with const-qualification)
        const T& operator[](unsigned int idx) const
        {
            if (idx >= _size)
                throw std::out_of_range("Index is out of bounds");
            return data[idx];
        }
        
        unsigned int size() const
        {
            return _size;
        }
};

#endif