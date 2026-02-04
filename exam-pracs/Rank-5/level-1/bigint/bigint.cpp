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
        digits = "0";
    else
        digits.erase(0, begin);
}

std::string bigint::getVal() const
{
    return digits;
}

std::string bigint::addstr(std::string s1, std::string s2) const
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
        res = char(sum % 10 + '0') + res;
    }
    return res;
}

bigint::bigint() : digits("0") {}

bigint::bigint(std::string value) : digits(value)
{
    trim_zeros();
}

bigint::bigint(int value)
{
    std::stringstream ss;
    ss << value;
    digits = ss.str();
    trim_zeros();
}

bigint::bigint(const bigint &other) : digits(other.digits) {}

bigint& bigint::operator=(const bigint &other)
{
    if (this != &other)
        digits = other.digits;
    return *this;
}

bigint::~bigint() {}

bigint& bigint::operator+=(const bigint& other)
{
    digits = addstr(digits, other.digits);
    return *this;
}

bigint bigint::operator+(const bigint& other) const 
{
    bigint temp;
    temp.digits = addstr(digits, other.digits);
    return temp; 
}

bigint& bigint::operator++()
{
    digits = addstr(digits, "1");
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp;
    digits = addstr(digits, "1");
    return temp;
}

bigint bigint::operator<<(int shift) const
{
    if (shift == 0)
        return *this;
    return bigint(digits + std::string(shift, '0'));
}

bigint bigint::operator>>(int shift) const 
{
    if (shift == 0)
        return *this;
    if (shift >= digits.length())
        return bigint();
    return bigint(digits.substr(0, digits.length() - shift));
}

bigint& bigint::operator<<=(int shift)
{
    if (shift != 0)
        digits += std::string(shift, '0');
    return *this;
}

bigint& bigint::operator>>=(int shift)
{
    if (shift == 0)
        return *this;
    if (shift >= digits.length())
        digits = "0";
    else
        digits = digits.substr(0, digits.length() - shift);
    return *this;
}

bigint bigint::operator>>(const bigint& shift) const 
{
    int total = 0;
    for (size_t i = 0; i < shift.digits.length(); ++i)
    {
        total = total * 10 + (shift.digits[i] - '0'); 
    }
    return (*this) >> total;
}

bigint bigint::operator<<(const bigint& shift) const
{
    int total = 0;
    for (size_t i = 0; i < shift.digits.length(); ++i)
    {
        total = total * 10 + (shift.digits[i] - '0'); 
    }
    return (*this) << total;
}

bigint& bigint::operator<<=(const bigint& shift)
{
    int total = 0;
    for (size_t i = 0; i < shift.digits.length(); ++i)
    {
        total = total * 10 + (shift.digits[i] - '0'); 
    }
    return (*this) <<= total;
}

bigint& bigint::operator>>=(const bigint& shift)
{
    int total = 0;
    for (size_t i = 0; i < shift.digits.length(); ++i)
    {
        total = total * 10 + (shift.digits[i] - '0'); 
    }
    return (*this) >>= total;
}

bool bigint::operator<(const bigint &other) const
{
    if (digits.length() != other.digits.length())
        return digits.length() < other.digits.length();
    return digits < other.digits;
}

bool bigint::operator>(const bigint &other) const
{
    return other < *this;
}

bool bigint::operator<=(const bigint &other) const
{
    return !(*this > other);
}

bool bigint::operator>=(const bigint &other) const
{
    return !(*this < other);
}

bool bigint::operator==(const bigint &other) const
{
    return digits == other.digits;
}

bool bigint::operator!=(const bigint &other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const bigint& bi)
{
    os << bi.getVal();
    return os;
}
