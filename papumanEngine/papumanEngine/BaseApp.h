#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Actor.h"

class
	BaseApp {
public:
	BaseApp() = default;
	~BaseApp() = default;
	
	// Funcion encargada de ejecutar la aplicacion en main
	int
		run();

	// Funcion de inicializacion
	bool
		initialize();

	// Funcion que se actualiza por frame
	void
		update();

	// Funcion de renderizado
	void
		render();

	void
		cleanup();
	void
		MoveCircle(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
	sf::Time deltaTime;
	sf::Clock clock;

	sf::Vector2f wayPoints[4] = {
		sf::Vector2f(100.0f, 100.0f),
		sf::Vector2f(200.0f, 100.0f),
		sf::Vector2f(200.0f, 200.0f),
		sf::Vector2f(100.0f, 200.0f)
	};
	int currentPoint = 0;  // Guardar el índice actual del waypoint entre frames
	float radiousToPoint = 1.0f;

	Window* m_window;
	sf::CircleShape* shape;
	EngineUtilities::TSharedPointer<Actor> Triangle;
	EngineUtilities::TSharedPointer<Actor> Circle;
};