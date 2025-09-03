/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:05:40 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/03 16:12:20 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

class PmergeMe
{
    private:
        std::vector<int> v;
        std::deque<int> dq;

        // helper for parsing
        bool isPositive(const std::string& str);
        
        // vector sorting
        void sortV(std::vector<int>& cont, int left, int right);
        void mergeV(std::vector<int>& cont, int left, int right);

        // sorting deque
        void sortD(std::deque<int>& cont, int left, int right);
        void mergeD(std::deque<int>& cont, int left, int right);
        
    public:
    // constructors + destructor
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

    // pre-sorting functions
        void loadNums(int ac, char **av);      
};
#endif
