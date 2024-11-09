#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Actor.h"

class Window;

/**
 * @class Entity
 * @brief Clase base para representar entidades en el sistema de actores.
 *
 * Las entidades pueden tener componentes, actualizarse y renderizarse en la ventana.
 */
class Entity {
public:
    /**
     * @brief Destructor de la clase Entity.
     *
     * Este es un destructor virtual que garantiza la correcta destrucción de las entidades derivadas.
     */
    virtual ~Entity() = default;

    /**
     * @brief Método para actualizar la entidad.
     *
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     *
     * @note Este método debe ser implementado por las clases derivadas para definir la lógica de actualización específica.
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief Método para renderizar la entidad en la ventana.
     *
     * @param window La ventana donde se va a renderizar la entidad.
     *
     * @note Este método debe ser implementado por las clases derivadas para definir la lógica de renderizado específica.
     */
    virtual void render(Window& window) = 0;

    /**
     * @brief Método para agregar un componente a la entidad.
     *
     * @param component El componente que se quiere agregar a la entidad.
     *
     * @tparam T Tipo de componente que se va a agregar, debe ser derivado de la clase Component.
     *
     * @note Este método asegura que el componente agregado sea del tipo correcto.
     */
    template<typename T>
    void addComponent(EngineUtilities::TSharedPointer<T> component) {
        static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
        components.push_back(component.template dynamic_pointer_cast<Component>());
    }

    /**
     * @brief Método para obtener un componente de la entidad.
     *
     * @tparam T Tipo del componente que se quiere obtener.
     *
     * @return EngineUtilities::TSharedPointer<T> El componente del tipo solicitado, si existe.
     *
     * @note Este método busca en la lista de componentes de la entidad y devuelve el primero que coincida con el tipo.
     */
    template<typename T>
    EngineUtilities::TSharedPointer<T> getComponent() {
        for (auto& component : components) {
            EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
            if (specificComponent) {
                return specificComponent;
            }
        }
        return EngineUtilities::TSharedPointer<T>();
    }

protected:
    std::vector<EngineUtilities::TSharedPointer<Component>> components; /**< Lista de componentes asociados a la entidad. */
};