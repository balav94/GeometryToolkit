#ifndef GEOMETRY_UTILS_HPP
#define GEOMETRY_UTILS_HPP

#include <tuple>
#include "Point.hpp"

std::tuple<double, double, double, double> getPlaneCoeffs(const Point& P1, const Point& P2, const Point& P3);

double getDistanceFromPlane(const std::tuple<double, double, double, double>& coeffs, const Point& P4);

std::tuple<double, double, double> getVector(const Point& Pa, const Point& Pb);

std::tuple<double, double, double> crossProduct(const std::tuple<double, double, double>& vec1, const std::tuple<double, double, double>& vec2);

double dotProduct(const std::tuple<double, double, double>& vec1, const std::tuple<double, double, double>& vec2);

bool isDegenerateTriangle(const Point& P1, const Point& P2, const Point& P3);

#endif // GEOMETRY_UTILS_HPP
