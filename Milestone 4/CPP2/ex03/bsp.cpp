/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:51:45 by gkaim             #+#    #+#             */
/*   Updated: 2025/07/04 16:53:44 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float sign(Point const& p1, Point const& p2, Point const& p3)
{
    float result = (p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat())
                - (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat());
    return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float d1 = sign(point, a, b);
    float d2 = sign(point, b, c);
    float d3 = sign(point, c, a);

    // bool negative = d1 < 0 || d2 < 0 || d3 < 0;
    // bool positive = d1 > 0 || d2 > 0 || d3 > 0;

    return (d1 > 0 && d2 > 0 && d3 > 0) ||
           (d1 < 0 && d2 < 0 && d3 < 0);
}