#include "ShapeFactory.h"

sf::Shape* ShapeFactory::createShape(ShapeType shapeType) {
    m_shapeType = shapeType;
    switch (shapeType) {
    case NONE: // Caso para "NONE", no hace nada y sigue adelante
        return nullptr;

    case CIRCLE: { // Caso para círculo
        sf::CircleShape* circle = new sf::CircleShape(10.0f); // Círculo con radio de 10
        circle->setFillColor(sf::Color::White); // Color blanco
        m_shape = circle;
        return circle;
    }

    case RECTANGLE: { // Caso para rectángulo
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f)); // Tamaño 100x50
        rectangle->setFillColor(sf::Color::White); // Color blanco
        m_shape = rectangle;
        return rectangle;
    }

    case TRIANGLE: { // Caso para triángulo
        sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3); // Círculo de 3 lados (triángulo)
        triangle->setFillColor(sf::Color::White); // Color blanco
        m_shape = triangle;
        return triangle;
    }

    default: // Caso por defecto si el tipo de forma no coincide con ninguno de los anteriores
        return nullptr;
    }
}
