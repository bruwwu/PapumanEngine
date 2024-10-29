#pragma once
#include "Prerequisites.h"

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
        render();

    void 
        destroy();

    void 
        baseStyleGUI();

    // Añadir mensaje a la consola
    void 
        inConsoleMessage(const std::map<ConsoleTypeError, std::vector<std::string>>& m_programMessage);

private:
};
