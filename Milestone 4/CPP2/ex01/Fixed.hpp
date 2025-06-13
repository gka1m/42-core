/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:11:49 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/13 15:11:25 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int fixedPtVal;
        static const int fracBits = 8;
    
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float flt);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif