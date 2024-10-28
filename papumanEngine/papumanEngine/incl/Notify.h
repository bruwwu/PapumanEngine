#pragma once
#include "Prerequisites.h"
#include "GUI.h"

class Notify {
public:
    // Constructor privado para evitar instanciaci?n directa
    Notify() {};

    // M?todo est?tico para obtener la instancia ?nica del RegistroActividad
    static
        Notify* getInstance() {
        if (m_instance != nullptr) {
            return m_instance;
        }
        else {
            m_instance = new Notify;
        }
        return m_instance;
    }

    // Destructor por defecto
    ~Notify() = default;

    // M?todo para registrar una actividad en el registro
    void
        addMessage(ConsoleTypeError msgType, const std::string& _msg) {
        m_programMessage.insert(make_pair(msgType, _msg));
    }

    void
        notify(ConsoleTypeError msgType, const std::string& _msg) {

        GUI* gui;
        gui->inConsoleMessage(m_programMessage);
    }

    // M?todo para obtener y mostrar las mensajes registrados
    /*void
    getMessage() {
    }*/

    std::map<ConsoleTypeError, std::string> showNotification() {
        return m_programMessage;
    }

private:
    static Notify* m_instance; // Instancia Unica
    std::map<ConsoleTypeError, std::string> m_programMessage; // Mapa para almacenar las actividades registradas
};