#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
// main provided by project
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

// own main
int main() {
    std::cout << "=== Testing Default Constructor ===" << std::endl;
    Array<int> a;
    std::cout << "a.size(): " << a.size() << std::endl;

    std::cout << "\n=== Testing Parameterized Constructor ===" << std::endl;
    Array<int> b(5);
    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = i * 10;

    std::cout << "Contents of b: ";
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    Array<int> c(b);
    std::cout << "Contents of c (copied from b): ";
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Modifying c to test deep copy ===" << std::endl;
    c[0] = 999;
    std::cout << "b[0]: " << b[0] << " (should be unchanged)" << std::endl;
    std::cout << "c[0]: " << c[0] << std::endl;

    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    Array<int> d;
    d = b;
    std::cout << "Contents of d (assigned from b): ";
    for (unsigned int i = 0; i < d.size(); ++i)
        std::cout << d[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Modifying d to test deep copy ===" << std::endl;
    d[1] = 888;
    std::cout << "b[1]: " << b[1] << " (should be unchanged)" << std::endl;
    std::cout << "d[1]: " << d[1] << std::endl;

    std::cout << "\n=== Testing Bounds Checking ===" << std::endl;
    try {
        std::cout << "Accessing b[10]: ";
        std::cout << b[10] << std::endl; // should throw
    } catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Accessing b[-1]: ";
        std::cout << b[-1] << std::endl; // should throw
    } catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}