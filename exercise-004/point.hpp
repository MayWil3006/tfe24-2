#ifndef POINT_HPP
#define POINT_HPP

#include <fmt/format.h>

class Point {
private:
    double x_;
    double y_;

public:
    Point(); //Standardkonstruktor

    Point(double x, double y); //Konstruktor mit Initialisierung

    // Verschiebe den Punkt um (dx, dy)
    void move(double dx, double dy);

    // Gib die Koordinaten aus
    void print() const;

    double distance_to(const Point& other) const;
};

#endif // POINT_HPP