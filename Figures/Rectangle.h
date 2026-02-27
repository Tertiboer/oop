#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
protected:
    int width, height;
    
public:
    Rectangle(int x, int y, int w, int h, sf::Color color = sf::Color::Green)
        : Shape(x, y, color), width(w), height(h) {}
    
    void draw(sf::RenderWindow& window) override {
        sf::RectangleShape rectangle(sf::Vector2f(static_cast<float>(width), 
                                                  static_cast<float>(height)));
        rectangle.setPosition(sf::Vector2f(static_cast<float>(position.x), 
                                          static_cast<float>(position.y)));
        rectangle.setFillColor(color);
        window.draw(rectangle);
    }
    
    std::string toString() const override {
        return "Rectangle(" + std::to_string(position.x) + ", " + 
               std::to_string(position.y) + ", " + 
               std::to_string(width) + ", " + 
               std::to_string(height) + ")";
    }
};

#endif
