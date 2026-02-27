#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Point.h"

class Shape {
protected:
    sf::Color color;
    Point position;
    
public:
    Shape(int x = 0, int y = 0, sf::Color color = sf::Color::White) 
        : position(x, y), color(color) {}
    
    virtual ~Shape() {}
    
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual std::string toString() const = 0;
    
    void setColor(sf::Color newColor) { color = newColor; }
    sf::Color getColor() const { return color; }
    
    void setPosition(int x, int y) { position = Point(x, y); }
    Point getPosition() const { return position; }
};

#endif
