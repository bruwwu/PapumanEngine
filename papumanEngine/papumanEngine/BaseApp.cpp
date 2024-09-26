/*
 * MIT License
 *
 * Copyright (c) 2024 Roberto Charreton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * In addition, any project or software that uses this library or class must include
 * the following acknowledgment in the credits:
 *
 * "This project uses software developed by Roberto Charreton and Attribute Overload."
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/
#include "BaseApp.h"

int
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statement, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		deltaTime = clock.restart();
		update();
		render();
	}

	cleanup();
	return 0;
}

bool
BaseApp::initialize() {
	m_window = new Window(800, 600, "Galvan Engine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}
	shape = new sf::CircleShape(10.0f);

	if (!shape) {
		ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
		return false;
	}


	// Circle Actor
	Circle = EngineUtilities::MakeShared<Actor>("Circle");
	if (!Circle.isNull()) {
		Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
		Circle->getComponent<ShapeFactory>()->setPosition(200.0f, 200.0f);
		Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);
	}



	// Triangle Actor
	Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
	if (!Triangle.isNull()) {
		Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
	}

	return true;
}

void
BaseApp::update() {
	if (!Circle.isNull()) {
		MoveCircle(deltaTime.asSeconds(), Circle);
	}
}

void
BaseApp::render() {
	m_window->clear();
	m_window->draw(*shape);
	if (!Triangle.isNull()) {
		Triangle->render(*m_window);
	}
	if (!Circle.isNull()) {
		Circle->render(*m_window);
	}

	m_window->display();
}

void
BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
	delete shape;
}

void
BaseApp::MoveCircle(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {

	if (!circle || circle.isNull()) return;
	// Definir los waypoints
	static sf::Vector2f wayPoints[4] = {
		sf::Vector2f(100.0f, 100.0f),
		sf::Vector2f(200.0f, 100.0f),
		sf::Vector2f(200.0f, 200.0f),
		sf::Vector2f(100.0f, 200.0f)
	};

	static int currentPoint = 0;  // Guardar el índice actual del waypoint entre frames

	// Obtener la posición actual del círculo
	sf::Vector2f currentPos = Circle->getComponent<ShapeFactory>()->getShape()->getPosition();

	// Calcular la distancia entre el waypoint actual y la posición del círculo
	sf::Vector2f direction = wayPoints[currentPoint] - currentPos;
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Mover el círculo hacia el waypoint actual
	Circle->getComponent<ShapeFactory>()->Seek(wayPoints[currentPoint],
		200.0f,  // Velocidad
		deltaTime,
		10.0f);

	// Cambiar al siguiente waypoint si el círculo está dentro del rango de 10 unidades
	if (distance < 10.0f) {
		currentPoint = (currentPoint + 1) % 4;
	}
}
