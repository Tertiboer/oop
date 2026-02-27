#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Figures/Point.h"
#include "Figures/Shape.h"
#include "Figures/Line.h"
#include "Figures/Rectangle.h"
#include "Figures/Ellipse.h"
#include "Figures/Triangle.h"
#include "Figures/Circle.h"
#include "Figures/Square.h"
#include "FiguresList.h"

int main() {
    // Создаем список фигур
    FiguresList figuresList;
    
    // Статическая инициализация - добавляем различные фигуры
    figuresList.addFigure(std::make_unique<Line>(50, 50, 150, 50, sf::Color::Red));
    figuresList.addFigure(std::make_unique<Rectangle>(200, 50, 100, 60, sf::Color::Green));
    figuresList.addFigure(std::make_unique<Ellipse>(400, 80, 60, 30, sf::Color::Blue));
    figuresList.addFigure(std::make_unique<Triangle>(50, 200, 150, 200, 100, 280, sf::Color::Yellow));
    figuresList.addFigure(std::make_unique<Circle>(300, 220, 40, sf::Color::Cyan));
    figuresList.addFigure(std::make_unique<Square>(450, 200, 60, sf::Color::Magenta));
    
    // Выводим информацию о фигурах в консоль
    figuresList.printAllInfo();
    std::cout << "Total figures: " << figuresList.getCount() << std::endl;
    
    // Создаем окно для рисования
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(600, 400)), "Graphics Figures");
    
    // Основной цикл
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear(sf::Color::Black);
        
        // Рисуем все фигуры
        figuresList.drawAll(window);
        
        window.display();
    }
    
    return 0;
}

