/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkaim <gkaim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:57:36 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/04 16:42:25 by gkaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void printCon(const T& cont, const std::string& label)
{
    std::cout << label;
    for (size_t i = 0; i < cont.size(); i++)
        std::cout << cont[i] << " ";
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integers...>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.loadNums(ac, av);

        // Print unsorted sequence
        printCon(sorter.getVector(), "Before: ");

        // --------- Vector sort + timing ---------
        std::vector<int> vec = sorter.getVector(); // copy original
        clock_t startVec = clock();
        sorter.sortV(vec, 0, vec.size() - 1);
        clock_t endVec = clock();

        // --------- Deque sort + timing ---------
        std::deque<int> deq = sorter.getDeque(); // copy original
        clock_t startDeq = clock();
        sorter.sortD(deq, 0, deq.size() - 1);
        clock_t endDeq = clock();

        // Print sorted sequence
        printCon(vec, "After:  ");

        // Logging times
        double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
        double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << vec.size()
                  << " elements with std::vector : " 
                  << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;

        std::cout << "Time to process a range of " << deq.size()
                  << " elements with std::deque  : "
                  << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}