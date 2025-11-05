#ifndef BIGINT_HPP
#define BIGINT_HPP


#include <iostream>
#include <string>
#include <algorithm>

class bigint
{
    private:
        std::string digits;
        void trim_zeros();
        std::string addstr(std::string s1, std::string s2);

    public:
    // constructors + destructor
        bigint();
        bigint(std::string value);
        bigint(int value);
        bigint(const bigint& other);
        ~bigint();

        std::string getVal();
        
        // assignment
        bigint& operator+(bigint &other);
        bigint& operator-(bigint &other);

        // mathematical
        bigint operator+(bigint &other);
        bigint& operator++();
        bigint operator++(int);

        // shifting
        bigint operator<<(int shift);
        bigint operator>>(int shift);
        bigint& operator<<=(int shift);
        bigint& operator>>=(int shift);
        bigint operator>>(bigint& shift);
        bigint operator<<(bigint& shift);
        bigint& operator<<=(bigint& shift);
        bigint& operator>>=(bigint& shift);

        // comparison
        bool operator<(bigint &other);
        bool operator>(bigint &other);
        bool operator<=(bigint &other);
        bool operator>=(bigint &other);
        bool operator==(bigint &other);
        bool operator!=(bigint &other);
};

std::ostream& operator<<(std::ostream& os, bigint& bi);
#endif