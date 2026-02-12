/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:54:56 by kagoh             #+#    #+#             */
/*   Updated: 2026/01/29 13:00:38 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe constrructed" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) : v(other.v), dq(other.dq)
{
    std::cout << "PmergeMe copied" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        v = other.v;
        dq = other.dq;
    }
    std::cout << "PmergeMe assigned" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe destroyed" << std::endl;
}

bool PmergeMe::isPositive(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    long val = std::atol(str.c_str());
    return val > 0;
}

void PmergeMe::loadNums(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string token(av[i]);
        if (!isPositive(token))
        {
            throw std::invalid_argument("Error: Invalid input '" + token + "'");
        }
        int num = std::atoi(token.c_str());
        v.push_back(num);
        dq.push_back(num);
    }
}

void PmergeMe::sortV(std::vector<int>& cont)
{
    if (cont.size() <= 1)
        return;

    std::vector<int> smalls;
    std::vector<int> largers;

    // Used to keep pairing relationship
    std::vector<std::pair<int, int> > pairs;

    // 1. Pair elements
    for (size_t i = 0; i + 1 < cont.size(); i += 2)
    {
        int a = cont[i];
        int b = cont[i + 1];
        if (a < b)
        {
            smalls.push_back(a);
            largers.push_back(b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
        {
            smalls.push_back(b);
            largers.push_back(a);
            pairs.push_back(std::make_pair(b, a));
        }
    }

    bool hasOdd = (cont.size() % 2 != 0);
    int odd = 0;
    if (hasOdd)
        odd = cont.back();

    // 2. Recursively sort the largers
    sortV(largers);

    // 2a. Reorder smalls to match sorted largers
    std::vector<int> orderedSmalls;
    for (size_t i = 0; i < largers.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].second == largers[i])
            {
                orderedSmalls.push_back(pairs[j].first);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    smalls = orderedSmalls;

    // 3. Insert smalls into sorted largers using Jacobsthal sequence
    std::vector<int> result = largers;

    // Insert first small at the beginning
    result.insert(result.begin(), smalls[0]);

    // Generate Jacobsthal sequence for remaining insertions
    std::vector<size_t> jacobSeq;
    generateJacobsthal(jacobSeq, smalls.size());

    // Create insertion order based on Jacobsthal sequence
    std::vector<bool> inserted(smalls.size(), false);
    inserted[0] = true; // Already inserted first element

    for (size_t k = 0; k < jacobSeq.size(); k++)
    {
        size_t jacobIdx = jacobSeq[k];
        
        // Insert from jacobIdx down to previous Jacobsthal number
        size_t prevJacob = (k > 0) ? jacobSeq[k - 1] : 0;
        
        for (size_t i = jacobIdx; i > prevJacob && i < smalls.size(); i--)
        {
            if (!inserted[i])
            {
                int val = smalls[i];
                std::vector<int>::iterator it =
                    std::lower_bound(result.begin(), result.end(), val);
                result.insert(it, val);
                inserted[i] = true;
            }
        }
    }

    // Insert any remaining elements not covered by Jacobsthal
    for (size_t i = 1; i < smalls.size(); i++)
    {
        if (!inserted[i])
        {
            int val = smalls[i];
            std::vector<int>::iterator it =
                std::lower_bound(result.begin(), result.end(), val);
            result.insert(it, val);
        }
    }

    // Insert odd element if present
    if (hasOdd)
    {
        std::vector<int>::iterator it =
            std::lower_bound(result.begin(), result.end(), odd);
        result.insert(it, odd);
    }

    cont = result;
}

void PmergeMe::generateJacobsthal(std::vector<size_t>& seq, size_t n) {
    seq.clear();
    size_t j0 = 0, j1 = 1;
    while (j1 <= n) {
        seq.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
}

void PmergeMe::sortD(std::deque<int>& cont)
{
    if (cont.size() <= 1)
        return;

    std::deque<int> smalls;
    std::deque<int> largers;
    std::deque<std::pair<int, int> > pairs;

    // 1. Pair elements
    for (size_t i = 0; i + 1 < cont.size(); i += 2)
    {
        int a = cont[i];
        int b = cont[i + 1];

        if (a < b)
        {
            smalls.push_back(a);
            largers.push_back(b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
        {
            smalls.push_back(b);
            largers.push_back(a);
            pairs.push_back(std::make_pair(b, a));
        }
    }

    bool hasOdd = (cont.size() % 2 != 0);
    int odd = 0;
    if (hasOdd)
        odd = cont.back();

    // 2. Recursively sort the largers
    sortD(largers);

    // 2a. Reorder smalls to match sorted largers
    std::deque<int> orderedSmalls;
    for (size_t i = 0; i < largers.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].second == largers[i])
            {
                orderedSmalls.push_back(pairs[j].first);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    smalls = orderedSmalls;

    // 3. Insert smalls into sorted largers using Jacobsthal sequence
    std::deque<int> result = largers;

    // Insert first small at the beginning
    result.insert(result.begin(), smalls[0]);

    // Generate Jacobsthal sequence for remaining insertions
    std::deque<size_t> jacobSeq;
    generateJacobsthal(jacobSeq, smalls.size());

    // Create insertion order based on Jacobsthal sequence
    std::vector<bool> inserted(smalls.size(), false);
    inserted[0] = true; // Already inserted first element

    for (size_t k = 0; k < jacobSeq.size(); k++)
    {
        size_t jacobIdx = jacobSeq[k];
        
        // Insert from jacobIdx down to previous Jacobsthal number
        size_t prevJacob = (k > 0) ? jacobSeq[k - 1] : 0;
        
        for (size_t i = jacobIdx; i > prevJacob && i < smalls.size(); i--)
        {
            if (!inserted[i])
            {
                int val = smalls[i];
                std::deque<int>::iterator it =
                    std::lower_bound(result.begin(), result.end(), val);
                result.insert(it, val);
                inserted[i] = true;
            }
        }
    }

    // Insert any remaining elements not covered by Jacobsthal
    for (size_t i = 1; i < smalls.size(); i++)
    {
        if (!inserted[i])
        {
            int val = smalls[i];
            std::deque<int>::iterator it =
                std::lower_bound(result.begin(), result.end(), val);
            result.insert(it, val);
        }
    }

    // Insert odd element if present
    if (hasOdd)
    {
        std::deque<int>::iterator it =
            std::lower_bound(result.begin(), result.end(), odd);
        result.insert(it, odd);
    }

    cont = result;
}

void PmergeMe::generateJacobsthal(std::deque<size_t>& seq, size_t n) {
    seq.clear();
    size_t j0 = 0, j1 = 1;
    while (j1 <= n) {
        seq.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
}

const std::vector<int>& PmergeMe::getVector() const
{
    return v;
}

const std::deque<int>& PmergeMe::getDeque() const
{
    return dq;
}