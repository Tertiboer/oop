#ifndef CIRCLE_H
#define CIRCLE_H

#include "Ellipse.h"

class Circle : public Ellipse {
public:
    Circle(int x, int y, int radius, sf::Color color = sf::Color::Cyan)
        : Ellipse(x, y, radius, radius, color) {}
    
    std::string toString() const override {
        return "Circle(" + std::to_string(position.x) + ", " + 
               std::to_string(position.y) + ", " + 
               std::to_string(radiusX) + ")";
    }
};

#endif
