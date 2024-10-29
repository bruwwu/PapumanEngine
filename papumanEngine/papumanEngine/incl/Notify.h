#pragma once
#include "Prerequisites.h"
#include "GUI.h"

class Notify {
public:
    // Método estático para obtener la instancia única de Notify
    static Notify* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new Notify;
        }
        return m_instance;
    }

    // Destructor por defecto
    ~Notify() = default;

    // Método para agregar un mensaje al registro
    void addMessage(ConsoleTypeError code, const std::string& message) {
        m_programMessage[code].push_back(message); // Añadir al vector de mensajes para el tipo de error
    }



    // Método para mostrar todas las notificaciones
    std::map<ConsoleTypeError, std::vector<std::string>> showNotifications() const {
        return m_programMessage;  // Devuelve todas las notificaciones agrupadas por tipo
    }

    // Método de log (actualmente vacío, puedes implementarlo)
    /*void Log(const std::string& message) {
        ConsoleTypeError code = ConsoleTypeError::INFO;
        m_programMessage[code].push_back(message);
    }*/

private:
    // Constructor privado para evitar instanciación directa
    Notify() {}

    static Notify* m_instance; // Instancia única

    // Mapa para almacenar los mensajes clasificados por tipo de error
    std::map<ConsoleTypeError, std::vector<std::string>> m_programMessage;
};
