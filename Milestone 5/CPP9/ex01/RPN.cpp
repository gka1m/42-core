/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:12:29 by kagoh             #+#    #+#             */
/*   Updated: 2025/09/03 11:00:52 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "RPN cpnstructed" << std::endl;
}

RPN::RPN(const RPN& other) : stack(other.stack)
{
    std::cout << "RPN copied" << std::endl;   
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        stack = other.stack;
    return *this;       
}

RPN::~RPN()
{
    // std::cout << "RPN destroyed" << std::endl;
}

bool RPN::isOp(const std::string& token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/"; 
}

void RPN::applyOp(const std::string& op)
{
    if (stack.size() < 2)
        std::cerr << "Error: not enough operands" << std::endl;

    int rhs = stack.top();
    stack.pop();
    int lhs = stack.top();
    stack.pop();
    
    int result;
    if (op == "+")
        result = lhs + rhs;
    else if (op == "-")
        result = lhs - rhs;
    else if (op == "*")
        result = lhs * rhs;
    else if (op == "/")
    {
        if (rhs == 0)
            throw std::runtime_error("Error: division by 0");
        result = lhs / rhs;
    }
    stack.push(result);
}

int RPN::evaluate(const std::string& expr)
{
    std::istringstream iss(expr);
    std::string token;
    
    while (iss >> token)
    {
        if (isOp(token))
            applyOp(token);

        else
        {
            if (token.size() != 1 || !isdigit(token[0]))
                throw std::runtime_error("Error: invalid token " + token);
            int value = token[0] - '0';
            stack.push(value);
        
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    return stack.top();
}