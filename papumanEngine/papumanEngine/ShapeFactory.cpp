#include "ShapeFactory.h"

sf::Shape* ShapeFactory::createShape(ShapeType shapeType) {
    m_shapeType = shapeType;
    switch (shapeType) {
    case NONE: // Caso para "NONE", no hace nada y sigue adelante
        return nullptr;

    case CIRCLE: { // Caso para c�rculo
        sf::CircleShape* circle = new sf::CircleShape(10.0f); // C�rculo con radio de 10
        circle->setFillColor(sf::Color::White); // Color blanco
        m_shape = circle;
        return circle;
    }

    case RECTANGLE: { // Caso para rect�ngulo
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f)); // Tama�o 100x50
        rectangle->setFillColor(sf::Color::White); // Color blanco
        m_shape = rectangle;
        return rectangle;
    }

    case TRIANGLE: { // Caso para tri�ngulo
        sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3); // C�rculo de 3 lados (tri�ngulo)
        triangle->setFillColor(sf::Color::White); // Color blanco
        m_shape = triangle;
        return triangle;
    }

    default: // Caso por defecto si el tipo de forma no coincide con ninguno de los anteriores
        return nullptr;
    }
}
