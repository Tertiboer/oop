#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <vector>

class Triangle : public Shape {
private:
    Point point2, point3;
    
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3, 
             sf::Color color = sf::Color::Yellow)
        : Shape(x1, y1, color), point2(x2, y2), point3(x3, y3) {}
    
    void draw(sf::RenderWindow& window) override {
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, sf::Vector2f(static_cast<float>(position.x), 
                                          static_cast<float>(position.y)));
        triangle.setPoint(1, sf::Vector2f(static_cast<float>(point2.x), 
                                          static_cast<float>(point2.y)));
        triangle.setPoint(2, sf::Vector2f(static_cast<float>(point3.x), 
                                          static_cast<float>(point3.y)));
        triangle.setFillColor(color);
        window.draw(triangle);
    }
    
    std::string toString() const override {
        return "Triangle(" + std::to_string(position.x) + ", " + 
               std::to_string(position.y) + ", " + 
               std::to_string(point2.x) + ", " + 
               std::to_string(point2.y) + ", " + 
               std::to_string(point3.x) + ", " + 
               std::to_string(point3.y) + ")";
    }
};

#endif
