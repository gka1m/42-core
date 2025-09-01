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

    public:
    // constructors + destructor
        bigint();
        bigint(std::string value);
        bigint(int value);
        bigint(const bigint& other);
        ~bigint();
};
#endif