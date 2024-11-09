#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "ShapeFactory.h"
#include "Actor.h"
#include "GUI.h"

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

	//Vector de actores
	std::vector<EngineUtilities::TSharedPointer <Actor>> m_actors;


	Window* m_window;
	EngineUtilities::TSharedPointer<Actor> Triangle;
	EngineUtilities::TSharedPointer<Actor> Circle;
	EngineUtilities::TSharedPointer<Actor> Track;

	// Seek Activity
	int currentWaypoint = 0;

		std::vector<sf::Vector2f> waypoints = {
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
		{80.0f, 45.0f},
		 // Punto más bajo
		};
	sf::Texture texture;
	sf::Texture DamBolaTxt;
	GUI m_GUI;
};