#include "BaseApp.h"

int
BaseApp::run() {
	initialize();
	while (m_window->isOpen()) {
		m_window->handleEvents();
		update();
		render();
	}

	cleanup();
	return 0;
}

void
BaseApp::initialize() {
	m_window = new Window(800, 600, "Galvan Engine");
	shape = new sf::CircleShape(100.0f);
	shape->setFillColor(sf::Color::Green);
}

void
BaseApp::update() {
}

void
BaseApp::render() {
	m_window->clear();
	m_window->draw(*shape);
	m_window->display();
}

void
BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
	delete shape;
}