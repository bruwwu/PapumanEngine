#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

/**
 * @class Transform
 * @brief Clase que representa un componente de transformación, incluyendo posición, rotación y escala.
 */
class Transform : public Component {
public:
    /**
     * @brief Constructor de Transform. Inicializa la posición a (0, 0), rotación a (0, 0) y escala a (1, 1).
     */
    Transform()
        : position(0.0f, 0.0f), rotation(0.0f, 0.0f), scale(1.0f, 1.0f),
        Component(ComponentType::TRANSFORM) {}

    /**
     * @brief Destructor virtual de Transform.
     */
    virtual
            ~Transform() = default;

    /**
     * @brief Actualiza el componente de transformación.
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     */
    void 
            update(float deltaTime) override {}

    /**
     * @brief Renderiza el componente de transformación.
     * @param window La ventana donde se renderiza el componente.
     */
    void 
        render(Window window) override {}

    /**
     * @brief Destruye el componente de transformación.
     */
    void 
        destroy() {};

    /**
     * @brief Método Seek que permite que el objeto se mueva hacia una posición objetivo.
     * @param targetPosition La posición objetivo a la que el objeto se desplazará.
     * @param speed La velocidad a la que se mueve el objeto.
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     * @param range La distancia mínima al objetivo a la cual el objeto se detendrá.
     */
    void 
        Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range) {
        sf::Vector2f direction = targetPosition - position;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (length > range) {
            direction /= length;  // Normaliza el vector
            position += direction * speed * deltaTime;
        }
    }

    /**
     * @brief Establece la posición del objeto.
     * @param _position La nueva posición del objeto.
     */
    void 
        setPosition(const sf::Vector2f& _position) {
            position = _position;
    }

    /**
     * @brief Establece la rotación del objeto.
     * @param _rotation La nueva rotación del objeto.
     */
    void setRotation(const sf::Vector2f& _rotation) {
        rotation = _rotation;
    }

    /**
     * @brief Establece la escala del objeto.
     * @param _scale La nueva escala del objeto.
     */
    void setScale(const sf::Vector2f& _scale) {
        scale = _scale;
    }

    /**
     * @brief Obtiene la posición del objeto.
     * @return Una referencia a la posición del objeto.
     */
    sf::Vector2f& getPosition() {
        return position;
    }

    /**
     * @brief Obtiene la rotación del objeto.
     * @return Una referencia a la rotación del objeto.
     */
    sf::Vector2f& getRotation() {
        return rotation;
    }

    /**
     * @brief Obtiene la escala del objeto.
     * @return Una referencia a la escala del objeto.
     */
    sf::Vector2f& getScale() {
        return scale;
    }

private:
    sf::Vector2f position;  ///< Posición del objeto
    sf::Vector2f rotation;  ///< Rotación del objeto
    sf::Vector2f scale;     ///< Escala del objeto
};
