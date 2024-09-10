#pragma once
#include "Prerequisites.h"
#include "Window.h"

class
	BaseApp {
public:
	BaseApp() = default;
	~BaseApp() = default;

	// Funcion encargada de ejecutar la aplicacion en main
	int
		run();

	// Funcion de inicializacion
	void
		initialize();

	// Funcion que se actualiza por frame
	void
		update();

	// Funcion de renderizado
	void
		render();

	void
		cleanup();

private:
	Window* m_window;
	sf::CircleShape* shape;
};