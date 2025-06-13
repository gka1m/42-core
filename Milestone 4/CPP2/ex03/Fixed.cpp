/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:16:37 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/13 16:15:51 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPtVal(0) {}

Fixed::Fixed(const int value)
{
    fixedPtVal = value << fracBits;
}

Fixed::Fixed(const float flt)
{
    fixedPtVal = roundf(flt * (1 << fracBits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->fixedPtVal = other.fixedPtVal;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
    return this->fixedPtVal;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPtVal = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)fixedPtVal / (1 << fracBits);
}

int Fixed::toInt( void ) const
{
    return fixedPtVal >> fracBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out <<fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const 
{
    return this->fixedPtVal > other.fixedPtVal;
}

bool Fixed::operator<(const Fixed& other) const 
{
    return this->fixedPtVal < other.fixedPtVal;
}

bool Fixed::operator>=(const Fixed& other) const 
{
    return this->fixedPtVal >= other.fixedPtVal;
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return this->fixedPtVal <= other.fixedPtVal;
}

bool Fixed::operator==(const Fixed& other) const 
{
    return this->fixedPtVal == other.fixedPtVal;
}

bool Fixed::operator!=(const Fixed& other) const 
{
    return this->fixedPtVal != other.fixedPtVal;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    this->fixedPtVal++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->fixedPtVal--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->fixedPtVal++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixedPtVal--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}