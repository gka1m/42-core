/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:40:58 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/13 16:04:45 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;

};

float sign(Point const& p1, Point const& p2, Point const& p3);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif