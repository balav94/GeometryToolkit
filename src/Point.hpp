#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
    double x, y, z;

public:
    Point(double a, double b, double c);

    ~Point() = default;

    void print() const;

    double get_X_coord() const;
    double get_Y_coord() const;
    double get_Z_coord() const;
};

#endif // POINT_HPP
