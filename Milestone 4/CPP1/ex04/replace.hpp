/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:26:40 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/11 15:23:37 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

bool copyFile(const std::string& filename, const std::string& copied);
std::string replaceLine(const std::string& line, const std::string& s1, const std::string& s2);
bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);
void replaceUsingStdReplace(const std::string& filename, const std::string& s1, const std::string& s2);

#endif
