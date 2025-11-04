#pragma once
#include <cmath>
#include <fmt/core.h>  // für fmt::print

class Point {
public:
    // Membervariablen
    int x_;
    int y_;

    // Konstruktoren
    Point() : x_{0}, y_{0} {}                // Standardkonstruktor
    Point(int x, int y) : x_{x}, y_{y} {}    // Konstruktor mit Werten

    // Methoden
    void move(int dx, int dy);                    // Punkt verschieben
    double distance_to(const Point &other) const; // Euklidische Distanz
    void print() const;                           // Punkt ausgeben
};
