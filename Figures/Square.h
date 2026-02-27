#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square(int x, int y, int side, sf::Color color = sf::Color::Magenta)
        : Rectangle(x, y, side, side, color) {}
    
    std::string toString() const override {
        return "Square(" + std::to_string(position.x) + ", " + 
               std::to_string(position.y) + ", " + 
               std::to_string(width) + ")";
    }
};

#endif
