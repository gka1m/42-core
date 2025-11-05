/*
Name: bigint
Expected files: bigint.hpp bigint.cpp

In computer science a bignum is an objext representing an arbitrary precision number, 
this is useful when you want to store a number bigger than SIZE_MAX without any loss
of precision. This is often achieved by storing an array on a string containing
the different "parts" of the number.

Create a class called bigint that will store an arbitrary precision unsigned integer.

Your class must support addition, comparison and "digitshift"(like bitshift but instead
of shifting the bits you will shift the digits in base 10, e.g.:
(42 << 3 == 42000) and (1337 >> 2 == 13)).

Your bigint must be printable with the << operator (in base 10) and the output should
not contain any leading zeros.

You will find a main in this directory that must work with your class.*/

#include "bigint.hpp"

void bigint::trim_zeros()
{
    if (digits.empty())
    {
        digits = "0";
        return;
    }

    size_t begin = digits.find_first_not_of('0');
    if (begin == std::string::npos)
        digits = '0';
    digits.erase(0, begin);
}

std::string bigint::getVal()
{
    return digits;
}

std::string bigint::addstr(std::string s1, std::string s2)
{
    std::string res = "";
    int s1_len = s1.length() - 1;
    int s2_len = s2.length() - 1;
    int carry = 0;

    while (s1_len >= 0 || s2_len >= 0 || carry != 0)
    {
        int sum = carry;
        if (s1_len >= 0)
        {
            sum += s1[s1_len] - '0';
            s1_len--;
        }
        if (s2_len >= 0)
        {
            sum += s2[s2_len] - '0';
            s2_len--;
        }
        carry = sum / 10;
        res += char(sum % 10 + '0') + res;
    }
    return res;
}

bigint::bigint() : digits("0") {}

bigint::bigint(std::string value) : digits(value)
{
    trim_zeros();
}

bigint::bigint(int value) : digits(std::to_string(value))
{
    trim_zeros();
}

bigint::bigint(const bigint &other) : digits(other.digits) {}

bigint::~bigint() {}

