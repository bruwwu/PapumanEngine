#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Actor.h"

class Window;

class
    Entity {
public:
    virtual
        ~Entity() = default;

    virtual void
        update(float deltaTime) = 0;
    virtual void
        render(Window window) = 0;

    template<typename T>
    void
        addComponent(EngineUtilities::TSharedPointer<T> component) {
        static_addert(std::is_base_of<Component, T>::value, "T must be derived from Component");
        components.push_back(component);
    }

    template<typename T>
    EngineUtilities::TSharedPointer<T>
        getComponent() {
        for (auto& component : components)
        {
            EngineUtilities::TSharedPointer<T> specificComponent = std::dynamic_pointer_cast<T>(component);
            if (specificComponent)
            {
                return specificComponent;
            }
        }
        return nullptr;
    }

protected:
    bool isActive;
    int id;
    std::vector<EngineUtilities::TSharedPointer<Component>> component;

};