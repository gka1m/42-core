/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:15:43 by kagoh             #+#    #+#             */
/*   Updated: 2025/12/10 12:35:56 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

template <typename T>
void increment(T& value)
{
	++value;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"apple", "banana", "cherry"};

	std::cout << "Original int array:\n";
	iter(intArray, 5, print<int>);

	iter(intArray, 5, increment<int>);

	std::cout << "\nAfter increment:\n";
	iter(intArray, 5, print<int>);

	std::cout << "\nString array:\n";
	iter(strArray, 3, print<std::string>);

	const int constarr[] = {10, 20, 30};
	std::cout << "const int array: " << std::endl;
	iter(constarr, 3, print<int>);
	
	// iter(constarr, 3, increment<int>);
	return 0;
}