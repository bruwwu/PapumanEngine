#pragma once
#include "Prerequisites.h"
#include "GUI.h"

/**
 * @class Notify
 * @brief Clase que gestiona las notificaciones y los mensajes de consola.
 *
 * Esta clase implementa el patrón Singleton para asegurar que haya solo una instancia de las notificaciones.
 * Permite agregar mensajes clasificados por tipo de error y mostrarlos cuando sea necesario.
 */
class Notify {
public:
    /**
     * @brief Obtiene la instancia única de la clase Notify.
     *
     * @return Instancia única de la clase Notify.
     *
     * @note Este método implementa el patrón Singleton para garantizar que solo haya una instancia de Notify.
     */
    static Notify* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new Notify;
        }
        return m_instance;
    }

    /**
     * @brief Destructor por defecto de la clase Notify.
     *
     * @note No tiene implementación adicional, pero puede ser extendido en el futuro si es necesario liberar recursos.
     */
    ~Notify() = default;

    /**
     * @brief Agrega un mensaje al registro de notificaciones.
     *
     * @param code Tipo de error o notificación (ConsoleTypeError).
     * @param message Mensaje que se agrega al registro.
     *
     * @note Este método clasifica los mensajes por tipo de error y los almacena en un mapa.
     */
    void addMessage(ConsoleTypeError code, const std::string& message) {
        m_programMessage[code].push_back(message); // Añadir al vector de mensajes para el tipo de error
    }

    /**
     * @brief Muestra todas las notificaciones agrupadas por tipo de error.
     *
     * @return Un mapa que contiene los mensajes agrupados por tipo de error (ConsoleTypeError).
     *
     * @note Este método devuelve todas las notificaciones almacenadas en el objeto Notify.
     */
    std::map<ConsoleTypeError, std::vector<std::string>> showNotifications() const {
        return m_programMessage;  // Devuelve todas las notificaciones agrupadas por tipo
    }

    // Método de log (actualmente vacío)
    /*void Log(const std::string& message) {
        ConsoleTypeError code = ConsoleTypeError::INFO;
        m_programMessage[code].push_back(message);
    }*/

private:
    /**
     * @brief Constructor privado para evitar la creación directa de instancias.
     *
     * @note Este constructor asegura que la clase Notify siga el patrón Singleton.
     */
    Notify() {}

    static Notify* m_instance; // Instancia única de Notify

    /**
     * @brief Mapa para almacenar los mensajes clasificados por tipo de error.
     *
     * Este mapa utiliza un `ConsoleTypeError` como clave para clasificar los mensajes, y almacena los mensajes como vectores de cadenas.
     */
    std::map<ConsoleTypeError, std::vector<std::string>> m_programMessage;
};
