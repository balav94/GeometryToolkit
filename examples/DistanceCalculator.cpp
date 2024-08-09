#include <iostream>
#include <math.h>
#include "Point.hpp"
#include "GeometryUtils.hpp"
#include "input.hpp"

void calculateDistanceUsingPlaneEquationMethod(const Point& P1, const Point& P2, const Point& P3, const Point& P4) {
    auto coeffs = getPlaneCoeffs(P1, P2, P3);
    double dist = getDistanceFromPlane(coeffs, P4);
    std::cout << "Distance using plane coefficients: " << dist << std::endl;
}

void calculateDistanceUsingVectorProducts(const Point& P1, const Point& P2, const Point& P3, const Point& P4) {
    auto vec1 = getVector(P1, P2);
    auto vec2 = getVector(P1, P3);
    auto norm_vec = crossProduct(vec1, vec2);
    auto vec3 = getVector(P1, P4);

    double dist = fabs(dotProduct(norm_vec, vec3)) / sqrt(dotProduct(norm_vec, norm_vec));
    std::cout << "Distance using cross product: " << dist << std::endl;
}

int main() {
    std::cout << "Choose the method to calculate the distance:" << std::endl;
    std::cout << "1. Using plane coefficients" << std::endl;
    std::cout << "2. Using cross product" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cerr << "Invalid choice. Please enter 1 or 2." << std::endl;
        return 1;
    }

    std::cout << "Provide the points of the triangle (x1 y1 z1 x2 y2 z2 x3 y3 z3):" << std::endl;

    double x1, y1, z1, x2, y2, z2, x3, y3, z3;

    if (!getValidInput(x1, y1, z1) || !getValidInput(x2, y2, z2) || !getValidInput(x3, y3, z3)) {
        std::cerr << "Failed to get valid input for triangle points. Exiting." << std::endl;
        return 1;
    }

    Point P1(x1, y1, z1), P2(x2, y2, z2), P3(x3, y3, z3);

    // Check for degenerate triangle in which case there is no unique plane passing through the three points
    if (isDegenerateTriangle(P1, P2, P3) == true) {
        std::cerr << "Triangle formed by the three points is degenerate" << std::endl;
        return -1;
    }

    std::cout << "Provide the coordinates of the external point (x4 y4 z4):" << std::endl;

    double x4, y4, z4;
    
    if (!getValidInput(x4, y4, z4)) {
        std::cerr << "Failed to get valid input for external point. Exiting." << std::endl;
        return 1;
    }

    Point P4(x4, y4, z4);

    if (choice == 1) {
        calculateDistanceUsingPlaneEquationMethod(P1, P2, P3, P4);
    } else if (choice == 2) {
        calculateDistanceUsingVectorProducts(P1, P2, P3, P4);
    } else {
        std::cerr << "Invalid choice!" << std::endl;
    }

    return 0;
}
