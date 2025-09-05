/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:54:56 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/05 10:52:52 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

// void PmergeMe::mergeV(std::vector<int>& cont, int left, int right)
// {
//     int mid = (left + right) / 2;
//     std::vector<int> tmp;
//     int i = left, j = mid + 1;

//     while (i <= mid && j <= right)
//     {
//         if (cont[i] < cont[j])
//             tmp.push_back(cont[i++]);
//         else
//             tmp.push_back(cont[j++]);
//     }
//     while (i <= mid)
//         tmp.push_back(cont[i++]);
//     while (j <= right)
//         tmp.push_back(cont[j++]);
//     for (int k = 0; k < (int)tmp.size(); k++)
//         cont[left + k] = tmp[k];
// }

// void PmergeMe::sortV(std::vector<int>& cont, int left, int right)
// {
//     if (left < right)
//     {
//         int mid = (left + right) / 2;
//         sortV(cont, left, mid);
//         sortV(cont, mid + 1, right);
//         mergeV(cont, left, right);
//     }
// }

void PmergeMe::sortV(std::vector<int>& cont) {
    if (cont.size() <= 1)
        return;

    // 1. Pair elements
    std::vector<int> smalls;
    std::vector<int> largers;
    for (size_t i = 0; i + 1 < cont.size(); i += 2) {
        int a = cont[i], b = cont[i+1];
        if (a < b) {
            smalls.push_back(a);
            largers.push_back(b);
        } else {
            smalls.push_back(b);
            largers.push_back(a);
        }
    }
    // Handle odd element
    if (cont.size() % 2 != 0)
        smalls.push_back(cont.back());

    // 2. Recursively sort the largers
    sortV(largers);

    // 3. Insert the smalls into sorted largers
    std::vector<int> result = largers;

    // Insert first small at beginning
    result.insert(result.begin(), smalls[0]);

    // Jacobsthal sequence generation
    std::vector<size_t> jacobSeq;
    generateJacobsthal(jacobSeq, smalls.size() - 1);

    for (size_t idx = 1; idx < smalls.size(); ++idx) {
        size_t pos = (idx - 1 < jacobSeq.size()) ? jacobSeq[idx - 1] : idx;
        if (pos >= smalls.size()) pos = idx;

        int val = smalls[pos];
        // Binary search insert
        std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), val);
        result.insert(it, val);
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

// void PmergeMe::mergeD(std::deque<int>& cont, int left, int right)
// {
//     int mid = (left + right) / 2;
//     std::vector<int> tmp;
//     int i = left, j = mid + 1;

//     while (i <= mid && j <= right)
//     {
//         if (cont[i] < cont[j])
//             tmp.push_back(cont[i++]);
//         else
//             tmp.push_back(cont[j++]);
//     }
//     while (i <= mid)
//         tmp.push_back(cont[i++]);
//     while (j <= right)
//         tmp.push_back(cont[j++]);
//     for (int k = 0; k < (int)tmp.size(); k++)
//         cont[left + k] = tmp[k];
// }

// void PmergeMe::sortD(std::deque<int>& cont, int left, int right)
// {
//     if (left < right)
//     {
//         int mid = (left + right) / 2;
//         sortD(cont, left, mid);
//         sortD(cont, mid + 1, right);
//         mergeD(cont, left, right);
//     }
// }

void PmergeMe::sortD(std::deque<int>& cont) {
    if (cont.size() <= 1)
        return;

    // 1. Pair elements
    std::deque<int> smalls;
    std::deque<int> largers;
    for (size_t i = 0; i + 1 < cont.size(); i += 2) {
        int a = cont[i], b = cont[i+1];
        if (a < b) {
            smalls.push_back(a);
            largers.push_back(b);
        } else {
            smalls.push_back(b);
            largers.push_back(a);
        }
    }
    // Handle odd element
    if (cont.size() % 2 != 0)
        smalls.push_back(cont.back());

    // 2. Recursively sort the largers
    sortD(largers);

    // 3. Insert the smalls into sorted largers
    std::deque<int> result = largers;

    // Insert first small at beginning
    result.insert(result.begin(), smalls[0]);

    // Jacobsthal sequence generation
    std::deque<size_t> jacobSeq;
    generateJacobsthal(jacobSeq, smalls.size() - 1);

    for (size_t idx = 1; idx < smalls.size(); ++idx) {
        size_t pos = (idx - 1 < jacobSeq.size()) ? jacobSeq[idx - 1] : idx;
        if (pos >= smalls.size()) pos = idx;

        int val = smalls[pos];
        // Binary search insert
        std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), val);
        result.insert(it, val);
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