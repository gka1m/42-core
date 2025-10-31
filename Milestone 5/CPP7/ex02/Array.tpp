/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:14:35 by gkaim             #+#    #+#             */
/*   Updated: 2025/10/31 14:33:10 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
Array<T>::Array() : data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : data(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
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

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx >= _size)
        throw std::out_of_range("index is out of bounds");
    return data[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx >= _size)
        throw std::out_of_range("index is out of bounds");
    return data[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}