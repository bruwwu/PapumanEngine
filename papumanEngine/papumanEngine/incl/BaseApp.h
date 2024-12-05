#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "ShapeFactory.h"
#include "ECS\Actor.h"
#include "GUI.h"

/**
 * @class BaseApp
 * @brief Clase base que gestiona la ejecución y ciclo de vida de la aplicación.
 *
 * Esta clase proporciona los métodos necesarios para ejecutar la aplicación,
 * manejar la inicialización, actualización por frame, renderizado y limpieza.
 */
class BaseApp {
public:
    /**
     * @brief Constructor por defecto de la clase BaseApp.
     */
    BaseApp() = default;

    /**
     * @brief Destructor por defecto de la clase BaseApp.
     */
    ~BaseApp() = default;


    int 
        run();


    bool 
        initialize();


    void 
        update();

 
    void 
        render();


    void 
        cleanup();

    void 
        MoveCircle(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
    /**
     * @brief Vector de actores en la escena.
     *
     * Esta lista almacena los actores que están activos en la escena.
     */
    std::vector<EngineUtilities::TSharedPointer<Actor>> m_actors;

    /**
     * @brief Puntero a la ventana.
     *
     * Este puntero apunta a la ventana donde se renderiza la aplicación.
     */
    Window* m_window;

    /**
     * @brief Punteros a actores específicos.
     *
     * Estos actores representan figuras específicas en la escena como un triángulo, círculo y track.
     */
    EngineUtilities::TSharedPointer<Actor> Triangle;
    EngineUtilities::TSharedPointer<Actor> Circle;
    EngineUtilities::TSharedPointer<Actor> Track;

    int currentWaypoint = 0;

    std::vector<Vector2> waypoints = { //Puntos para recorrido
        {80.0f, 350.0f},
        {80.0f, 555.0f},
        {900.0f, 555.0f}, // Punto más alto
        {900.0f, 350.0f},
        {750.0f, 350.0f}, // Bajada
        {750.0f, 260.0f},
        {900.0f, 260.0f}, // Bajada
        {900.0f, 45.0f},
        {580.0f, 45.0f},
        {550.0f, 150.0f},
        {390.0f, 150.0f},
        {390.0f, 45.0f},
        {80.0f, 45.0f}, // Punto más bajo
    };
    sf::Texture texture;
    sf::Texture DamBolaTxt;

    /**
     * @brief Instancia de la clase GUI para manejar la interfaz gráfica de usuario.
     *
     * Esta instancia es responsable de gestionar la GUI dentro de la aplicación.
     */
    GUI m_GUI;
};
