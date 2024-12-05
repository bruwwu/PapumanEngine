#include "BaseApp.h"
#include "Services\Notify.h"
#include "Services\ResourceManager.h"

Notify* Notify::m_instance = nullptr;

int
BaseApp::run() {

	

	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	m_GUI.init();

	while (m_window->isOpen()) {
		m_window->handleEvents();
		update();
		render();
	}
	

	cleanup();
	return 0;
}

bool
BaseApp::initialize() {
	Notify* noti = Notify::getInstance();
	ResourceManager& resourceManager = ResourceManager::getInstance();

	m_window = new Window(1920, 1080, "Papuman Engine");
	if (!m_window) {
		noti->addMessage(ConsoleTypeError::ERROR, "Error on window creation, pointer is null");
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}

	// Track Actor
	Track = EngineUtilities::MakeShared<Actor>("Track");
	if (!Track.isNull()) {
		Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

		// Establecer posición, rotación y escala desde Transform
		Track->getComponent<Transform>()->setTransform(Vector2(0.0f, 0.0f),
			Vector2(0.0f, 0.0f), Vector2(10.0f, 12.0f));

		// Cargar la textura de Track
		if (!resourceManager.loadTexture("yonded", "png")) {
			noti->addMessage(ConsoleTypeError::ERROR, "Error al cargar textura: yonded");
		}
		else {
			EngineUtilities::TSharedPointer<Texture> trackTexture = resourceManager.getTexture("yonded");
			if (trackTexture) {
				Track->getComponent<ShapeFactory>()->getShape()->setTexture(&trackTexture->getTexture());
			}
		}

		m_actors.push_back(Track);
	}
	else {
		noti->addMessage(ConsoleTypeError::ERROR, "Error - Nullpointer Reference");
		noti->addMessage(ConsoleTypeError::WARNING, "Warning - Missing Texture from source bin");
	}

	// Circle Actor
	Circle = EngineUtilities::MakeShared<Actor>("Circle");
	if (!Circle.isNull()) {
		Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);

		// Establecer posición, rotación y escala desde Transform
		Circle->getComponent<Transform>()->setTransform(Vector2(650.0f, 560.0f),
			Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));

		// Cargar la textura de Circle
		if (!resourceManager.loadTexture("dambola", "png")) {
			noti->addMessage(ConsoleTypeError::ERROR, "Error al cargar textura: dambola");
		}
		else {
			EngineUtilities::TSharedPointer<Texture> circleTexture = resourceManager.getTexture("dambola");
			if (circleTexture) {
				Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&circleTexture->getTexture());
			}
		}

		m_actors.push_back(Circle);
	}
	else {
		noti->addMessage(ConsoleTypeError::ERROR, "Error - Nullpointer Reference");
		noti->addMessage(ConsoleTypeError::WARNING, "Warning - Missing Texture from source bin");
	}

	return true;
}



void
BaseApp::update() {
	// Update window method
	Notify* noti = Notify::getInstance();
	m_window->update();

	// Mouse Position
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
		static_cast<float>(mousePosition.y));

	for (auto & actor : m_actors) {
		if (!actor.isNull()) {
			actor->update(m_window->deltaTime.asSeconds());
		}
	}
	if (!Circle.isNull()) {
		MoveCircle(m_window->deltaTime.asSeconds(), Circle);
	}
}

void
BaseApp::render() {
	Notify* noti = Notify::getInstance();
	m_window->clear();

	// Update the actors
	for (auto& actor : m_actors) {
		if (!actor.isNull()) {
			actor->render(*m_window);
		}
	}

	EngineUtilities::TSharedPointer<Actor> picol;


	// Mostrar el render en ImGui
	m_window->renderToTexture();  // Finaliza el render a la textura
	m_window->showInImGui();  
	m_GUI.inConsoleMessage(noti->showNotifications());// Muestra la textura en ImGui

	m_GUI.Inspector(m_actors);

	m_GUI.spawnShape(m_actors);


	m_window->render();
	m_window->display();



}

void
BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
}


void
BaseApp::MoveCircle(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
	
	// Verificar si el Circle es nulo
	if (!circle || circle.isNull()) {
		return;
	}

	// Obtener el componente Transform
	auto transform = circle->getComponent<Transform>();
	if (transform.isNull()) {
		return;
	}

	// Posición actual del destino (punto de recorrido)
	Vector2 targetPos = waypoints[currentWaypoint];

	// Llamar al Seek del Transform
	transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

	// Obtener la posición actual del actor desde Transform
	Vector2 currentPos = transform->getPosition();

	// Comprobar si el actor ha alcanzado el destino (o está cerca)
	float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

	if (distanceToTarget < 10.0f) { // Umbral para considerar que ha llegado

		currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a través de los puntos
		

	}
}