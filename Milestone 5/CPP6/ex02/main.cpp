/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:11:22 by kagoh             #+#    #+#             */
/*   Updated: 2025/10/30 15:18:12 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Base * generate(void);
// void identify(Base* p);
// void identify(Base& p);


/* randomly instantiates A, B or C and returns it as a pointer to Base
   demonstrates polymorphism */
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

/* uses dynamic_cast with pointers to safely check if base pointer can be converted to A*, B* or C*.
   if cast fails, return NULL, otherwise pointer is returned
   allows for safe runtime identification of the derived type */
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

/* uses dynamic_cast with references to safely check type at runtime.
   if cast fails, throw std::bad_cast, otherwise pointer is returned
   allows for safe runtime identification of the derived type.
   dynamic_cast demonstrates exception handling for failed casts */
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