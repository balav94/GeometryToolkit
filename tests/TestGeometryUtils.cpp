#include <iostream>
#include <cassert>
#include <math.h>
#include "Point.hpp"
#include "GeometryUtils.hpp"

void testDistCalcBaseCase() {
    Point P1(1, 0, 0), P2(0, 1, 0), P3(0, 0, 1);
    Point P4(1, 1, 1);

    // Using method 1
    auto coeffs = getPlaneCoeffs(P1, P2, P3);
    double dist1 = getDistanceFromPlane(coeffs, P4);
    assert(fabs(dist1 - (2/sqrt(3.0))) < 1e-6);

    // Using method 2
    auto vec1 = getVector(P1, P2);
    auto vec2 = getVector(P1, P3);
    auto norm_vec = crossProduct(vec1, vec2);
    auto vec3 = getVector(P1, P4);

    double dist2 = fabs(dotProduct(norm_vec, vec3)) / sqrt(dotProduct(norm_vec, norm_vec));
    assert(fabs(dist2 - (2/sqrt(3.0))) < 1e-6);
}

void testDistCalcCornerCase1() {
    Point P1(1, 0, 0), P2(0, 1, 0), P3(0, 0, 1);
    Point P4(1, 0, 0);

    // Using method 1
    auto coeffs = getPlaneCoeffs(P1, P2, P3);
    double dist1 = getDistanceFromPlane(coeffs, P4);
    assert(fabs(dist1) < 1e-6);

    // Using method 2
    auto vec1 = getVector(P1, P2);
    auto vec2 = getVector(P1, P3);
    auto norm_vec = crossProduct(vec1, vec2);
    auto vec3 = getVector(P1, P4);

    double dist2 = fabs(dotProduct(norm_vec, vec3)) / sqrt(dotProduct(norm_vec, norm_vec));
    assert(fabs(dist2) < 1e-6);
}

void testDistCalcCornerCase2() {
    Point P1(1, 0, 0), P2(0, 1, 0), P3(0, 0, 1);
    Point P4(1.0/3.0, 1.0/3.0, 1.0/3.0);

    // Using method 1
    auto coeffs = getPlaneCoeffs(P1, P2, P3);
    double dist1 = getDistanceFromPlane(coeffs, P4);
    assert(fabs(dist1) < 1e-6);

    // Using method 2
    auto vec1 = getVector(P1, P2);
    auto vec2 = getVector(P1, P3);
    auto norm_vec = crossProduct(vec1, vec2);
    auto vec3 = getVector(P1, P4);

    double dist2 = fabs(dotProduct(norm_vec, vec3)) / sqrt(dotProduct(norm_vec, norm_vec));
    assert(fabs(dist2) < 1e-6);
}

int main() {
    testDistCalcBaseCase();
    testDistCalcCornerCase1();
    testDistCalcCornerCase2();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
