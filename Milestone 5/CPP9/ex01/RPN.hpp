/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:15:48 by gkaim             #+#    #+#             */
/*   Updated: 2026/01/27 11:03:58 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <list> 

class RPN
{
    private:
        // std::stack<int> stack;
        std::stack<int, std::list<int> > stack;
        bool isOp(const std::string& token) const;
        void applyOp(const std::string& op);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int evaluate(const std::string& expr);
};
#endif