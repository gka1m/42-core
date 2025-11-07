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
        std::string addstr(std::string s1, std::string s2) const;

    public:
    // constructors + destructor
        bigint();
        bigint(std::string value);
        bigint(int value);
        bigint(const bigint& other);
        ~bigint();

        std::string getVal() const;
        
        // assignment
        bigint& operator+=(const bigint &other);
        bigint& operator=(const bigint &other);

        // mathematical
        bigint operator+(const bigint &other) const;
        bigint& operator++();
        bigint operator++(int);

        // shifting
        bigint operator<<(int shift) const;
        bigint operator>>(int shift) const;
        bigint& operator<<=(int shift);
        bigint& operator>>=(int shift);

        bigint operator>>(const bigint& shift) const;
        bigint operator<<(const bigint& shift) const;
        bigint& operator<<=(const bigint& shift);
        bigint& operator>>=(const bigint& shift);

        // comparison
        bool operator<(const bigint &other) const;
        bool operator>(const bigint &other) const;
        bool operator<=(const bigint &other) const;
        bool operator>=(const bigint &other) const;
        bool operator==(const bigint &other) const;
        bool operator!=(const bigint &other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& bi);
#endif