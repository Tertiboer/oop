#ifndef FIGURESLIST_H
#define FIGURESLIST_H

#include <vector>
#include <memory>
#include <iostream>
#include "Figures/Shape.h"

class FiguresList {
private:
    std::vector<std::unique_ptr<Shape>> figures;
    
public:
    void addFigure(std::unique_ptr<Shape> figure) {
        figures.push_back(std::move(figure));
    }
    
    void drawAll(sf::RenderWindow& window) {
        for (const auto& figure : figures) {
            figure->draw(window);
        }
    }
    
    void printAllInfo() {
        std::cout << "Figures in list:" << std::endl;
        for (const auto& figure : figures) {
            std::cout << "  " << figure->toString() << std::endl;
        }
    }
    
    size_t getCount() const { return figures.size(); }
};

#endif
