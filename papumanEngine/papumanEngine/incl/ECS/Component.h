#pragma once
class Window;

// Tipos de componentes disponibles en el juego.
enum ComponentType {
    NONE = 0,       /**< Sin tipo, valor predeterminado */
    TRANSFORM = 1,  /**< Componente de transformación (posición, rotación, escala) */
    SPRITE = 2,     /**< Componente de sprite (gráficos) */
    RENDERER = 3,   /**< Componente de renderizado */
    PHYSICS = 4,    /**< Componente de física */
    AUDIOSOURCE = 5, /**< Componente de fuente de audio */
    SHAPE = 6    ,
    TEXTURE = 7    /**< Componente de forma (geometría) */
};

/**
 * @class Component
 * @brief Clase base abstracta para todos los componentes del juego.
 *
 * Esta clase proporciona la estructura básica para todos los componentes que puedan ser
 * asociados a un actor en el juego, como componentes de transformación, gráficos, física, etc.
 */
class Component {

public:
    /**
     * @brief Constructor por defecto.
     */
    Component() = default;

    /**
     * @brief Constructor con tipo de componente.
     *
     * @param type Tipo de componente que se está creando.
     */
    Component
        (const ComponentType type) : m_type(type) {}

    /**
     * @brief Destructor virtual.
     *
     * @note Este destructor es virtual para permitir la correcta destrucción de clases derivadas.
     */
    virtual 
        ~Component() = default;

    /**
     * @brief Método virtual puro para actualizar el componente.
     *
     * @param deltatime El tiempo transcurrido desde la última actualización.
     *
     * @note Este método debe ser implementado por las clases derivadas para definir su lógica de actualización.
     */
    virtual void 
        update(float deltatime) = 0;

    /**
     * @brief Método virtual puro para renderizar el componente.
     *
     * @param window La ventana en la que se va a renderizar el componente.
     *
     * @note Este método debe ser implementado por las clases derivadas para definir su lógica de renderizado.
     */
    virtual void 
        render(Window window) = 0;

    /**
     * @brief Obtiene el tipo del componente.
     *
     * @return El tipo del componente (ComponentType).
     */
    ComponentType 
        getType() const { return m_type; }

protected:
    ComponentType m_type; /**< Tipo de componente */
};
