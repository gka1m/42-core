/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:29:14 by kagoh             #+#    #+#             */
/*   Updated: 2025/06/25 13:26:42 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

bool copyFile(const std::string& filename, const std::string& copied)
{
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: cannot open input file " << filename << std::endl;
        return false;
    }

    std::ofstream outFile(copied.c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: cannot open output file " << copied 
        << "for writing. Check file permissions or disk space" << std::endl;
        return false;
    }
    
    std::string line;
    
    while (std::getline(inFile, line))
        outFile << line << "\n";
    inFile.close();
    outFile.close();
    return true;
}

std::string replaceLine(const std::string& line, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
    {
        std::cerr << "String to be replaced (s1) cannot be empty" << std::endl;
        return line;
    }

    std::string result;
    size_t pos = 0;
    size_t found;
    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        result += line.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += line.substr(pos);
    return result;
}

bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: cannot open file " << filename << " for reading\n";
        return false;
    }

    std::string replaced;
    std::string line;
    while (std::getline(inFile, line))
        replaced += replaceLine(line, s1, s2) + "\n";
    inFile.close();

    std::ofstream outFile(filename.c_str(), std::ios::trunc);
    if (!outFile.is_open())
    {
        std::cerr << "Cannot open output file " << filename << " for writing\n";
        return false;
    }
    
    outFile << replaced;
    outFile.close();
    return true;
}

void replaceUsingStdReplace(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: cannot open file for std::replace comparison\n";
        return;
    }

    std::ofstream outFile((filename + ".stdreplace").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: cannot create stdreplace output file\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2); // Standard replace
            pos += s2.length();
        }
        outFile << line << '\n';
    }
    inFile.close();
    outFile.close();
}
