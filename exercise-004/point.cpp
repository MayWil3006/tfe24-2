#include "point.hpp"

// Standardkonstruktor
Point::Point() : x_(0), y_(0) {}

// Konstruktor mit Werten
Point::Point(double x, double y) : x_(x), y_(y) {}

void Point::move(double dx, double dy) {
    x_ += dx;
    y_ += dy;
}

void Point::print() const {
    fmt::print("({}, {})\n", x_, y_);
}

double Point::distance_to(const Point& other) const {
    return std::hypot(double(x_ - other.x_), double(y_ - other.y_));
}