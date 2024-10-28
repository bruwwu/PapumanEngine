#include "Notify.h"
#include "Prerequisites.h"
#include "GUI.h"

Notify& Notify::getInstance() {
    static Notify instance;  // Se crea solo una vez y se reutiliza
    return instance;
}
void Notify::notify(int code, ConsoleTypeError type) {
    // Verificar si el código existe en el mapa
    auto it = m_programMessage.find(code);
    if (it != m_programMessage.end()) {
        // Encontró el mensaje, ahora lo envía a la consola de la GUI
        GUI gui;
        gui.addMessageToConsole(it->second, type);  // Pasar el tipo y el mensaje encontrado
    }
}
void Notify::addMessage(int code, const std::string& message) {
    m_programMessage[code] = message;
}