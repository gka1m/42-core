/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:38:11 by kagoh             #+#    #+#             */
/*   Updated: 2025/07/28 16:56:26 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main() 
{
    {
        std::cout << "=== MutantStack Test ===" << std::endl;

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Stack contents: ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Reverse order: ";
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "\n=== std::list Test ===" << std::endl;

        std::list<int> mlist;

        mlist.push_back(5);
        mlist.push_back(17);

        std::cout << "Top (back): " << mlist.back() << std::endl;

        mlist.pop_back();

        std::cout << "Size after pop: " << mlist.size() << std::endl;

        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);

        std::cout << "List contents: ";
        for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Reverse order: ";
        for (std::list<int>::reverse_iterator rit = mlist.rbegin(); rit != mlist.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


// // subject main
// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }