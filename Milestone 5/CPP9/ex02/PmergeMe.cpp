/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:54:56 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/03 16:11:47 by kagoh            ###   ########.fr       */
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
            throw std::invalid_argument("Error: Invalid input '" + token + "'");\
        int num = std::atoi(token.c_str());
        v.push_back(num);
        dq.push_back(num);
    }
}

void PmergeMe::mergeV(std::vector<int>& cont, int left, int right)
{
    int mid = (left + right) / 2;
    std::vector<int> tmp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (cont[i] < cont[j])
            tmp.push_back(cont[i++]);
        else
            tmp.push_back(cont[j++]);
    }
    while (i <= mid)
        tmp.push_back(cont[i++]);
    while (j <= right)
        tmp.push_back(cont[j++]);
    for (int k = 0; k < (int)tmp.size(); k++)
        cont[left + k] = tmp[k];
}

void PmergeMe::sortV(std::vector<int>& cont, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        sortV(cont, left, mid);
        sortV(cont, mid + 1, right);
        mergeV(cont, left, right);
    }
}

void PmergeMe::mergeD(std::deque<int>& cont, int left, int right)
{
    int mid = (left + right) / 2;
    std::vector<int> tmp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (cont[i] < cont[j])
            tmp.push_back(cont[i++]);
        else
            tmp.push_back(cont[j++]);
    }
    while (i <= mid)
        tmp.push_back(cont[i++]);
    while (j <= right)
        tmp.push_back(cont[j++]);
    for (int k = 0; k < (int)tmp.size(); k++)
        cont[left + k] = tmp[k];
}

void PmergeMe::sortD(std::deque<int>& cont, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        sortD(cont, left, mid);
        sortD(cont, mid + 1, right);
        mergeD(cont, left, right);
    }
}
