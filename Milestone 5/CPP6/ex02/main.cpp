/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:11:22 by kagoh             #+#    #+#             */
/*   Updated: 2025/11/05 12:31:16 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Base * generate(void);
// void identify(Base* p);
// void identify(Base& p);

Base* generate(void)
{
    // std::srand(std::time(NULL));
    int chance = std::rand() % 3;
    if (chance == 0)
        return new A;
    else if (chance == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Random unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (...)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(...)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(...)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

// for randomness, RNG is seeded once at runtime
int main(void)
{
    std::srand(std::time(0));
    Base *obj = generate();
    
    std::cout << "Pointer identification: ";
    identify(obj);

    std::cout << "Reference identification: ";
    identify(*obj);

    delete obj;
    return 0;
}