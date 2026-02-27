#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape {
private:
    Point endPoint;
    
public:
    Line(int x1, int y1, int x2, int y2, sf::Color color = sf::Color::Red)
        : Shape(x1, y1, color), endPoint(x2, y2) {}
    
    void draw(sf::RenderWindow& window) override {
        sf::Vertex line[2];
        line[0].position = sf::Vector2f(static_cast<float>(position.x), 
                                        static_cast<float>(position.y));
        line[0].color = color;
        line[1].position = sf::Vector2f(static_cast<float>(endPoint.x), 
                                        static_cast<float>(endPoint.y));
        line[1].color = color;
        
        window.draw(line, 2, sf::PrimitiveType::Lines);
    }
    
    std::string toString() const override {
        return "Line(" + std::to_string(position.x) + ", " + 
               std::to_string(position.y) + ", " + 
               std::to_string(endPoint.x) + ", " + 
               std::to_string(endPoint.y) + ")";
    }
};

#endif
