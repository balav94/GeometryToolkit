#include <cassert>
#include <iostream>
#include "Point.hpp"
#include "GeometryUtils.hpp"

// Unit test for degenerate triangle detection
void testDegenerateTriangle() {
    // Case 1: Collinear points (degenerate triangle)
    Point P1(0, 0, 0);
    Point P2(1, 1, 1);
    Point P3(2, 2, 2);  // P3 is along the line P1P2

    assert(isDegenerateTriangle(P1, P2, P3) && "Test Case 1 Failed: Should detect degenerate triangle (collinear points).");

    // Case 2: Non-collinear points (non-degenerate triangle)
    Point P4(0, 0, 0);
    Point P5(1, 0, 0);
    Point P6(0, 1, 0);  // P4, P5, P6 form a valid triangle

    assert(!isDegenerateTriangle(P4, P5, P6) && "Test Case 2 Failed: Should detect non-degenerate triangle.");

    // Case 3: Almost collinear points (testing tolerance)
    Point P7(0, 0, 0);
    Point P8(1e-9, 1e-9, 1e-9);
    Point P9(2e-9, 2e-9, 2e-9);  // Very close to being collinear with P7 and P8

    assert(isDegenerateTriangle(P7, P8, P9) && "Test Case 3 Failed: Should detect degenerate triangle due to floating-point tolerance.");

    std::cout << "All degenerate triangle tests passed!" << std::endl;
}

int main() {
    testDegenerateTriangle();
    return 0;
}
