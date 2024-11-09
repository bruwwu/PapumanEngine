#pragma once 
#include "Prerequisites.h"
#include "ECS\Actor.h"
#include "ShapeFactory.h"

class Window;

/**
 * @class GUI
 * @brief Clase encargada de gestionar la interfaz gráfica de usuario (GUI).
 */
class GUI {
public:
    GUI() = default;
    ~GUI() = default;

    /**
     * @brief Inicializa la GUI aplicando el estilo base.
     */
    void
        init();

    /**
     * @brief Método de actualización de la GUI.
     *
     * @note Este método está pensado para implementaciones futuras si se requiere actualizar elementos de la interfaz.
     */
    void
        update();

    /**
     * @brief Método para renderizar la GUI en una ventana.
     *
     * @param window La ventana en la que se dibuja la GUI.
     *
     * @note Este método está diseñado para renderizar la interfaz gráfica, pero aún no tiene implementación.
     */
    void
        render(Window& window);

    /**
     * @brief Método para destruir o limpiar los recursos de la GUI.
     *
     * @note Este método está diseñado para implementaciones futuras si es necesario liberar recursos.
     */
    void
        destroy();

    /**
     * @brief Muestra un inspector con las propiedades de los actores en la escena.
     *
     * @param m_actors Lista de actores en la escena para su visualización y edición.
     */
    void
        Inspector(const std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actors);

    /**
     * @brief Establece el estilo base de la GUI, incluyendo colores y bordes.
     */
    void
        baseStyleGUI();

    /**
     * @brief Añade mensajes a la consola en la interfaz gráfica con diferentes colores según el tipo de error.
     *
     * @param m_programMessage Mapa que contiene los mensajes clasificados por tipo de error.
     */
    void
        inConsoleMessage(const std::map<ConsoleTypeError, std::vector<std::string>>& m_programMessage);

    /**
     * @brief Crea una nueva figura en la escena según las configuraciones del usuario.
     *
     * @param m_actors Lista donde se almacenan los actores creados.
     */
    void
        spawnShape(std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actors);

private:
    /**
     * @brief Vector de actores en la escena.
     */
    std::vector<EngineUtilities::TSharedPointer <Actor>> m_actors;

    /**
     * @brief Actor específico de la escena (Ejemplo: picol).
     */
    EngineUtilities::TSharedPointer<Actor> picol;
};
