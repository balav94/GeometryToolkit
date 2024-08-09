#include "GeometryUtils.hpp"
#include <math.h>

const double EPSILON = 1e-9;  // Tolerance for floating-point comparison

std::tuple<double, double, double, double> getPlaneCoeffs(const Point& P1, const Point& P2, const Point& P3) {
    double x1 = P1.get_X_coord(), y1 = P1.get_Y_coord(), z1 = P1.get_Z_coord();
    double x2 = P2.get_X_coord(), y2 = P2.get_Y_coord(), z2 = P2.get_Z_coord();
    double x3 = P3.get_X_coord(), y3 = P3.get_Y_coord(), z3 = P3.get_Z_coord();

    double a = y1 * (z2 - z3) + y2 * (z3 - z1) + y3 * (z1 - z2);
    double b = z1 * (x2 - x3) + z2 * (x3 - x1) + z3 * (x1 - x2);
    double c = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    double d = -(a * x1 + b * y1 + c * z1);

    return std::make_tuple(a, b, c, d);
}

double getDistanceFromPlane(const std::tuple<double, double, double, double>& coeffs, const Point& P4) {
    auto [a, b, c, d] = coeffs;

    double x4 = P4.get_X_coord(), y4 = P4.get_Y_coord(), z4 = P4.get_Z_coord();

    return fabs(a * x4 + b * y4 + c * z4 + d) / sqrt(a * a + b * b + c * c);
}

std::tuple<double, double, double> getVector(const Point& Pa, const Point& Pb) {
    double x1 = Pa.get_X_coord(), y1 = Pa.get_Y_coord(), z1 = Pa.get_Z_coord();
    double x2 = Pb.get_X_coord(), y2 = Pb.get_Y_coord(), z2 = Pb.get_Z_coord();

    return std::make_tuple(x2 - x1, y2 - y1, z2 - z1);
}

std::tuple<double, double, double> crossProduct(const std::tuple<double, double, double>& vec1, const std::tuple<double, double, double>& vec2) {
    auto [a1, b1, c1] = vec1;
    auto [a2, b2, c2] = vec2;

    return std::make_tuple(b1 * c2 - b2 * c1, c1 * a2 - c2 * a1, a1 * b2 - a2 * b1);
}

double dotProduct(const std::tuple<double, double, double>& vec1, const std::tuple<double, double, double>& vec2) {
    auto [a1, b1, c1] = vec1;
    auto [a2, b2, c2] = vec2;

    return a1 * a2 + b1 * b2 + c1 * c2;
}

// Function to calculate the magnitude of a vector
double magnitude(const std::tuple<double, double, double>& vec) {
    auto [x, y, z] = vec;
    return sqrt(x * x + y * y + z * z);
}

// Function to check if the points are collinear (degenerate triangle)
bool isDegenerateTriangle(const Point& P1, const Point& P2, const Point& P3) {
    // Calculate vectors P1P2 and P1P3
    auto vec1 = getVector(P1, P2);
    auto vec2 = getVector(P1, P3);
    
    // Calculate the cross product of vec1 and vec2
    auto cross = crossProduct(vec1, vec2);
    
    // Calculate the magnitude of the cross product
    double mag = magnitude(cross);
    
    // The points are collinear if the magnitude of the cross product is less than the tolerance
    return mag < EPSILON;
}