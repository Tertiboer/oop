#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <cmath>

class Ellipse : public Shape {
protected:
    int radiusX, radiusY;
    
public:
    Ellipse(int x, int y, int rx, int ry, sf::Color color = sf::Color::Blue)
        : Shape(x, y, color), radiusX(rx), radiusY(ry) {}
    
    void draw(sf::RenderWindow& window) override {
        sf::CircleShape ellipse(static_cast<float>(radiusX));
        ellipse.setPosition(sf::Vector2f(static_cast<float>(position.x - radiusX), 
                                        static_cast<float>(position.y - radiusY)));
        ellipse.setFillColor(color);
        
        // Масштабирование для создания эллипса
        if (radiusX != radiusY) {
            float scaleY = static_cast<float>(radiusY) / radiusX;
            ellipse.setScale(sf::Vector2f(1.0f, scaleY));
        }
        
        window.draw(ellipse);
    }
    
    std::string toString() const override {
        return "Ellipse(" + std::to_string(position.x) + ", " + 
               std::to_string(position.y) + ", " + 
               std::to_string(radiusX) + ", " + 
               std::to_string(radiusY) + ")";
    }
};

#endif
