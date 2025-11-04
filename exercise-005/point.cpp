#include "point.hpp"
#include <cmath>
#include <fmt/core.h>

// Punkt verschieben
void Point::move(int dx, int dy) {
    x_ += dx;
    y_ += dy;
}

// Distanz zwischen zwei Punkten berechnen (euklidisch)
double Point::distance_to(const Point &other) const {
    double dx = static_cast<double>(x_) - static_cast<double>(other.x_);
    double dy = static_cast<double>(y_) - static_cast<double>(other.y_);
    return std::sqrt(dx * dx + dy * dy);
}

// Punkt ausgeben
void Point::print() const {
    fmt::print("Point({}, {})\n", x_, y_);
}
