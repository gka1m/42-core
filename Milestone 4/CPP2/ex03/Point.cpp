/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:44:02 by gkaim             #+#    #+#             */
/*   Updated: 2025/06/13 15:51:35 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xV, const float yV) : x(xV), y(yV) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}
