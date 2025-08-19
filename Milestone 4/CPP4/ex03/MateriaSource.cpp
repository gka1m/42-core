/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:54:29 by kagoh             #+#    #+#             */
/*   Updated: 2025/08/18 10:27:02 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete templates[i];
            
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete templates[i];
        templates[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* mat)
{
    if (!mat)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!templates[i])
        {
            templates[i] = mat;
            return;
        }
    }
    delete mat;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return NULL;
}
