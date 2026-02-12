/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:05:40 by kagoh             #+#    #+#             */
/*   Updated: 2026/01/27 12:44:39 by kagoh            ###   ########.fr       */
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
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> v;
        std::deque<int> dq;
        
    public:
    // constructors + destructor
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

         // pre-sorting functions
        void loadNums(int ac, char **av);      
         // helper for parsing
        bool isPositive(const std::string& str);
        
        // vector sorting
        // void sortV(std::vector<int>& cont, int left, int right);
        // void mergeV(std::vector<int>& cont, int left, int right);

        void sortV(std::vector<int>& cont);
        void generateJacobsthal(std::vector<size_t>& seq, size_t n);

        // sorting deque
        // void sortD(std::deque<int>& cont, int left, int right);
        // void mergeD(std::deque<int>& cont, int left, int right);

        void sortD(std::deque<int>& cont);
        void generateJacobsthal(std::deque<size_t>& seq, size_t n);

        const std::vector<int>& getVector() const;
        const std::deque<int>& getDeque() const;
};
#endif
