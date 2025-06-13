/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:23:20 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/13 16:17:37 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// int main() 
// {
//     Point a(0.0f, 0.0f);
//     Point b(10.0f, 0.0f);
//     Point c(0.0f, 10.0f);

//     Point inside(2.0f, 2.0f);
//     Point outside(20.0f, 2.0f);
//     Point edge(0.0f, 5.0f);

//     std::cout << "Inside: " << bsp(a, b, c, inside) << "\n";   // Expected: 1
//     std::cout << "Outside: " << bsp(a, b, c, outside) << "\n"; // Expected: 0
//     std::cout << "On edge: " << bsp(a, b, c, edge) << "\n";    // Expected: 0 or 1 (depending on strictness)
// }

int main() 
{
    // Define triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    float x, y;
    std::cout << "Enter X coordinate of the point: ";
    std::cin >> x;

    std::cout << "Enter Y coordinate of the point: ";
    std::cin >> y;

    Point userPoint(x, y);

    bool result = bsp(a, b, c, userPoint);
    if (result)
        std::cout << "The point is inside the triangle.\n";
    else
        std::cout << "The point is outside the triangle.\n";

    return 0;
}