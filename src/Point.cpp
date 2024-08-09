#include "Point.hpp"

Point::Point(double a, double b, double c) : x{a}, y{b}, z{c} {}

void Point::print() const {
    std::cout << x << " " << y << " " << z << std::endl;
}

double Point::get_X_coord() const {
    return x;
}

double Point::get_Y_coord() const {
    return y;
}

double Point::get_Z_coord() const {
    return z;
}
