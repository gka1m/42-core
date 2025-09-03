/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:05:40 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/03 11:54:46 by kagoh            ###   ########.fr       */
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
        void mergde(std::deque<int>& cont, int left, int right);
        
    public:
    // constructors + destructor
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

    // pre-sorting functions
        void loadNums(int ac, char **av);
    // sort both
        void sortBoth();

    // printing functions for debugging
        void printBefore() const;
        void printAfter() const;
        void printV() const;
        void printD() const;
};
#endif
