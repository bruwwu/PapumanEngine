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

    void
        setTransform(const Vector2& pos, const Vector2& rot, const Vector2& scl) {
        position = pos;
        rotation = rot;
        scale = scl;
    }

    /**
     * @brief Método Seek que permite que el objeto se mueva hacia una posición objetivo.
     * @param targetPosition La posición objetivo a la que el objeto se desplazará.
     * @param speed La velocidad a la que se mueve el objeto.
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     * @param range La distancia mínima al objetivo a la cual el objeto se detendrá.
     */
    void
        Seek(const Vector2& targetPosition,
            float speed,
            float deltaTime,
            float range) {
        Vector2 direction = (targetPosition)-position;
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
        setPosition(const Vector2 _position) {
            position = _position;
    }

    /**
     * @brief Establece la rotación del objeto.
     * @param _rotation La nueva rotación del objeto.
     */
    void setRotation(const Vector2 _rotation) {
        rotation = _rotation;
    }

    /**
     * @brief Establece la escala del objeto.
     * @param _scale La nueva escala del objeto.
     */
    void setScale(const Vector2 _scale) {
        scale = _scale;
    }

    /**
     * @brief Obtiene la posición del objeto.
     * @return Una referencia a la posición del objeto.
     */
    Vector2 getPosition() {
        return position;
    }

    /**
     * @brief Obtiene la rotación del objeto.
     * @return Una referencia a la rotación del objeto.
     */
    Vector2 getRotation() {
        return rotation;
    }

    /**
     * @brief Obtiene la escala del objeto.
     * @return Una referencia a la escala del objeto.
     */
    Vector2 getScale() {
        return scale;
    }

private:
    Vector2 position;  ///< Posición del objeto
    Vector2 rotation;  ///< Rotación del objeto
    Vector2 scale;     ///< Escala del objeto
};
