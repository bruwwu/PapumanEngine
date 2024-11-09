#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"
#include "Transform.h"

/**
 * @class Actor
 * @brief Clase que representa un actor en el sistema de entidades.
 *
 * La clase `Actor` hereda de `Entity` y gestiona componentes asociados al actor, como su nombre,
 * y permite la obtención de componentes específicos a través de su sistema de componentes.
 */
class Actor : public Entity {
public:
    /**
     * @brief Constructor por defecto de la clase Actor.
     *
     * Inicializa el actor con valores predeterminados.
     */
    Actor() = default;

    /**
     * @brief Constructor de la clase Actor.
     *
     * @param actorName Nombre del actor.
     *
     * @note Inicializa el actor con el nombre proporcionado.
     */
    Actor(std::string actorName);

    /**
     * @brief Destructor de la clase Actor.
     *
     * El destructor se encarga de destruir el actor cuando ya no es necesario.
     */
    virtual ~Actor() = default;

    /**
     * @brief Método de actualización del actor.
     *
     * Este método actualiza el estado del actor en función del tiempo transcurrido.
     *
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     */
    void update(float deltaTime) override;

    /**
     * @brief Método de renderizado del actor.
     *
     * Este método se encarga de dibujar el actor en la ventana proporcionada.
     *
     * @param window La ventana en la que se dibuja el actor.
     */
    void render(Window& window) override;

    /**
     * @brief Método de destrucción del actor.
     *
     * Este método se utiliza para liberar los recursos asociados con el actor.
     */
    void destroy();

    /**
     * @brief Método para obtener un componente específico del actor.
     *
     * Utiliza el tipo de componente especificado como argumento de plantilla para buscar
     * el componente dentro de los componentes del actor. Si se encuentra el componente,
     * lo devuelve como un puntero compartido.
     *
     * @tparam T Tipo de componente a buscar (por ejemplo, Transform, ShapeFactory).
     *
     * @return Un puntero compartido al componente del tipo solicitado, o nullptr si no se encuentra.
     */
    template <typename T>
    EngineUtilities::TSharedPointer<T> getComponent();

    /**
     * @brief Nombre del actor.
     *
     * Esta propiedad almacena el nombre del actor, el cual se puede modificar
     * para identificar al actor en la escena.
     */
    std::string m_name = "Actor"; ///< Nombre del actor.
};

/**
 * @brief Método para obtener un componente específico de un actor.
 *
 * El propósito de esta función es buscar y devolver un componente específico de un actor,
 * utilizando el tipo de componente especificado como argumento de la plantilla.
 * Si el componente no se encuentra, la función devuelve un puntero compartido vacío.
 *
 * @tparam T Tipo de componente a buscar (por ejemplo, Transform, ShapeFactory).
 *
 * @return Un puntero compartido al componente del tipo solicitado, o nullptr si no se encuentra.
 */
template<typename T>
inline EngineUtilities::TSharedPointer<T> Actor::getComponent() {
    for (auto& component : components) {
        EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
        if (specificComponent) {
            return specificComponent;
        }
    }
    // Devuelve un TSharedPointer vacío si no se encuentra el componente
    return EngineUtilities::TSharedPointer<T>();
}
