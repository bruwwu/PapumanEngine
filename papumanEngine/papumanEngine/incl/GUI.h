#pragma once
#include "Prerequisites.h"
#include "Actor.h"
#include "ShapeFactory.h"

class Window;

class GUI {
public:
    GUI() = default;
    ~GUI() = default;

    void 
        init();

    void
        update();

    void
        render(Window& window);

    void 
        destroy();

    void
        Inspector(const std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actors);

    void 
        baseStyleGUI();

    // Añadir mensaje a la consola
    void 
        inConsoleMessage(const std::map<ConsoleTypeError, std::vector<std::string>>& m_programMessage);
   
    void
        spawnShape(std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actors);

private:
    //Vector de actores
    std::vector<EngineUtilities::TSharedPointer <Actor>> m_actors;
    EngineUtilities::TSharedPointer<Actor> picol;
};
