/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:36:18 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/11 15:23:21 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "replace.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sed <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string copied = filename + ".replace";

    if (!copyFile(filename, copied))
        return 1;

    if (!replaceInFile(copied, s1, s2))
        return 1;
    replaceUsingStdReplace(filename, s1, s2);
    return 0;
}