#include "vect2.hpp"

int main() {
    vect2 v1;
    std::cout << "v1 (default, expected {0, 0}): " << v1 << std::endl;

    vect2 v2(1, 2);
    std::cout << "v2 (expected {1, 2}): " << v2 << std::endl;

    const vect2 v3(v2);
    std::cout << "v3 (copy of v2, expected {1, 2}): " << v3 << std::endl;

    vect2 v4 = v2;
    std::cout << "v4 (copy of v2, expected {1, 2}): " << v4 << std::endl;

    v4++;
    std::cout << "v4++ (expected {2, 3}): " << v4 << std::endl;

    ++v4;
    std::cout << "++v4 (expected {3, 4}): " << v4 << std::endl;

    v2 += v3;
    std::cout << "v2 += v3 (expected {2, 4}): " << v2 << std::endl;

    v1 -= v2;
    std::cout << "v1 -= v2 (expected {-2, -4}): " << v1 << std::endl;

    v2 = v3 + v3 * 2;
    std::cout << "v2 = v3 + v3*2 (expected {3, 6}): " << v2 << std::endl;

    v2 = 3 * v2;
    std::cout << "v2 = 3 * v2 (expected {9, 18}): " << v2 << std::endl;

    v2 += v2 += v3;
    std::cout << "v2 += v2 += v3 (expected {20, 40}): " << v2 << std::endl;

    v1 *= 42;
    std::cout << "v1 *= 42 (expected {-84, -168}): " << v1 << std::endl;

    v1 = v1 - v1 + v1;
    std::cout << "v1 = v1 - v1 + v1 (expected {-84, -168}): " << v1 << std::endl;

    std::cout << "v1 components (expected [-84, -168]): [" << v1[0] << ", " << v1[1] << "]" << std::endl;

    v2[0] = 42;
    v2[1] = 43;
    std::cout << "After v2[0]=42, v2[1]=43 (expected {42, 43}): " << v2 << std::endl;

    std::cout << "v3 components (expected [1, 2]): [" << v3[0] << ", " << v3[1] << "]" << std::endl;

    v2 = -v3;
    std::cout << "v2 = -v3 (expected {-1, -2}): " << v2 << std::endl;

    std::cout << "v1 == v3? (expected 0): " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1? (expected 1): " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3? (expected 1): " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1? (expected 0): " << (v1 != v1) << std::endl;

    bool tempCompare = (vect2(2,2) * 2 == vect2(4,4));
    std::cout << "(2,2)*2 == (4,4)? (expected 1): " << tempCompare << std::endl;

    std::cout << "\n=== Final States ===" << std::endl;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;

    return 0;
}