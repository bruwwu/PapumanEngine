#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"
#include "Transform.h"

class
    Actor : Entity {
public:
    /*
     Constructor por defecto.
     */
    Actor() = default;

    Actor(std::string actorName);

   
    virtual
        ~Actor() = default;

    void
        update(float deltaTime) override;

    void
        render(Window& window) override;

    void
        destroy();

    template <typename T>
    EngineUtilities::TSharedPointer<T>
        getComponent();
private:
    std::string m_name = "Actor"; ///< Nombre del actor.
};

/**
 * El prop�sito de esta funci�n es buscar y devolver un componente espec�fico de un actor,
 * utilizando el tipo de componente especificado como argumento de la plantilla.
 * Si el componente no se encuentra, la funci�n devuelve nullptr.
 */
template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
    for (auto& component : components) {
        EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
        if (specificComponent) {
            return specificComponent;
        }
    }
    // Devuelve un TSharedPointer vac�o si no se encuentra el componente
    return EngineUtilities::TSharedPointer<T>();
}