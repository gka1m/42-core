#include "bigint.hpp"
#include <iostream>

int main() 
{
    // Test cases from the problem
    const bigint a(42);
    bigint b;
    bigint c(21);
    bigint d(a);
    bigint e(1337);
    bigint f("001230");  // Should strip leading zeros to "1230"
    
    // Test output
    std::cout << "Testing basic construction and output:" << std::endl;
    std::cout << "a(42): " << a << std::endl;
    std::cout << "b(): " << b << std::endl;
    std::cout << "c(21): " << c << std::endl;
    std::cout << "d(a): " << d << std::endl;
    std::cout << "e(1337): " << e << std::endl;
    std::cout << "f(\"001230\"): " << f << std::endl;
    
    std::cout << "\nTesting left shift (multiplication by 10^n):" << std::endl;
    bigint test1(12345);
    bigint result1 = test1 << 2;
    std::cout << "12345 << 2 = " << result1 << std::endl;
    std::cout << "Expected: 1234500" << std::endl;
    
    std::cout << "\nTesting right shift (division by 10^n):" << std::endl;
    bigint test2(12345);
    bigint result2 = test2 >> 2;
    std::cout << "12345 >> 2 = " << result2 << std::endl;
    std::cout << "Expected: 123" << std::endl;
    
    std::cout << "\nTesting addition:" << std::endl;
    bigint num1(999);
    bigint num2(1);
    bigint sum = num1 + num2;
    std::cout << "999 + 1 = " << sum << std::endl;
    
    bigint num3(12345);
    bigint num4(67890);
    bigint sum2 = num3 + num4;
    std::cout << "12345 + 67890 = " << sum2 << std::endl;
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    bigint assigned;
    assigned = a;
    std::cout << "assigned = a: " << assigned << std::endl;
    
    std::cout << "\nTesting edge cases:" << std::endl;
    bigint zero1(0);
    bigint zero2("000");
    std::cout << "bigint(0): " << zero1 << std::endl;
    std::cout << "bigint(\"000\"): " << zero2 << std::endl;
    
    bigint shifted_zero = zero1 << 5;
    std::cout << "0 << 5 = " << shifted_zero << std::endl;
    
    bigint big_shift = test1 >> 10;
    std::cout << "12345 >> 10 = " << big_shift << std::endl;

    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;

    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    return 0;
}