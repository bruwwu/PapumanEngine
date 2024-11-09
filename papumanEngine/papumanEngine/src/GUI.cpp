#include "GUI.h"
#include "Window.h"
#include "Actor.h"
#include "ShapeFactory.h"

ShapeFactory shapeFactory;

void 
GUI::init() {
	baseStyleGUI();
}

void 
	GUI::update() {
	// Implementación futura si es necesaria
}

void 
	GUI::render(Window& window) {
	// Implementación futura si es necesaria
}

void 
	GUI::destroy() {
	// Implementación futura si es necesaria
}

void
	GUI::Inspector(const std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actors) {
	static int selectedActorIndex = -1; // Para llevar el seguimiento del actor seleccionado

	ImGui::Begin("Inspector");

	ImGui::TextColored(ImVec4(1, 0, 1, 1), "%s", "Objetos creados en escena:\n");

	// Mostrar lista de actores en la jerarquía
	for (size_t i = 0; i < m_actors.size(); ++i) {
		const auto& actor = m_actors[i];
		if (actor) {
			// Crear un botón seleccionable para cada actor en la lista
			if (ImGui::Selectable(actor->m_name.c_str(), selectedActorIndex == static_cast<int>(i))) {
				selectedActorIndex = static_cast<int>(i); // Guardar el índice del actor seleccionado
			}
		}
	}

	// Mostrar propiedades si hay un actor seleccionado
	if (selectedActorIndex >= 0 && selectedActorIndex < static_cast<int>(m_actors.size())) {
		auto& selectedActor = m_actors[selectedActorIndex];
		if (selectedActor) {
			ImGui::Separator();
			ImGui::Text("Propiedades del Actor seleccionado:");

			// Posición y Escala
			sf::Vector2f position = selectedActor->getComponent<Transform>()->getPosition();
			if (ImGui::DragFloat2("Position", reinterpret_cast<float*>(&position), 1.0f)) {
				selectedActor->getComponent<Transform>()->setPosition(position);
			}
			sf::Vector2f scale = selectedActor->getComponent<Transform>()->getScale();
			if (ImGui::DragFloat2("Scale", reinterpret_cast<float*>(&scale), 1.0f)) {
				selectedActor->getComponent<Transform>()->setScale(scale);
			}

			// Selección de ShapeType
			static int currentShapeTypeIndex = 0; // Índice seleccionado para ShapeType
			const char* shapeTypes[] = { "EMPTY", "CIRCLE", "RECTANGLE", "TRIANGLE" }; // Enum de tipos de forma

			if (ImGui::Combo("Shape Type", &currentShapeTypeIndex, shapeTypes, IM_ARRAYSIZE(shapeTypes))) {
				// Asigna el tipo de forma según la selección
				ShapeType selectedShapeType = static_cast<ShapeType>(currentShapeTypeIndex);
				selectedActor->getComponent<ShapeFactory>()->createShape(selectedShapeType);
			}
		}
	}

	ImGui::End();
}

void 
	GUI::spawnShape(std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actors) {
	static ShapeType selectedShape = ShapeType::EMPTY;
	static ImVec4 color = ImVec4(1, 1, 1, 1);
	static sf::Vector2f position(0.0f, 0.0f);
	static sf::Vector2f scale(1.0f, 1.0f);

	ImGui::Begin("Spawner", nullptr, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMenuBar()) {
		if (ImGui::BeginMenu("ShapeTypes")) {
			if (ImGui::MenuItem("None")) selectedShape = ShapeType::EMPTY;
			if (ImGui::MenuItem("Circle")) selectedShape = ShapeType::CIRCLE;
			if (ImGui::MenuItem("Rectangle")) selectedShape = ShapeType::RECTANGLE;
			if (ImGui::MenuItem("Triangle")) selectedShape = ShapeType::TRIANGLE;
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::Text("Selected Shape: %s", selectedShape == ShapeType::EMPTY ? "None" :
		selectedShape == ShapeType::CIRCLE ? "Circle" :
		selectedShape == ShapeType::RECTANGLE ? "Rectangle" :
		"Triangle");

	if (selectedShape != ShapeType::EMPTY) {
		ImGui::Separator();

		ImGui::ColorEdit4("Color", (float*)&color);
		ImGui::DragFloat2("Position", reinterpret_cast<float*>(&position), 1.0f, 0.0f, 100.0f);
		ImGui::DragFloat2("Scale", reinterpret_cast<float*>(&scale), 1.0f, 0.1f, 10.0f);

		if (ImGui::Button("Spawn Shape")) {
			auto newActor = EngineUtilities::MakeShared<Actor>("NewActor");
			if (newActor) {
				auto shapeFactory = newActor->getComponent<ShapeFactory>();
				shapeFactory->createShape(selectedShape);
				shapeFactory->setFillColor(sf::Color(color.x * 255, color.y * 255, color.z * 255, color.w * 255));

				auto transform = newActor->getComponent<Transform>();
				transform->setPosition(position);
				transform->setScale(scale);

				m_actors.push_back(newActor);

				selectedShape = ShapeType::EMPTY;
				color = ImVec4(1, 1, 1, 1);
				position = sf::Vector2f(0.0f, 0.0f);
				scale = sf::Vector2f(1.0f, 1.0f);
			}
		}
	}
	else {
		ImGui::Text("Selecciona un tipo de figura desde el menu.");
	}

	ImGui::End();
}

// Mostrar la consola en ImGui
void 
	GUI::inConsoleMessage(const std::map<ConsoleTypeError, std::vector<std::string>>& m_programMessage) {
	ImGui::Begin("Console");

	for (const auto& pair : m_programMessage) {
		// Establece el color según el tipo de error y agrega el prefijo correspondiente
		ImVec4 color;
		std::string errorType;
		switch (pair.first) {
		case ConsoleTypeError::NORMAL:
			color = ImVec4(1, 1, 1, 1);  // Blanco para NORMAL
			errorType = "[NORMAL]: ";
			break;
		case ConsoleTypeError::WARNING:
			color = ImVec4(1, 1, 0, 1);  // Amarillo para WARNING
			errorType = "[WARNING]: ";
			break;
		case ConsoleTypeError::ERROR:
			color = ImVec4(1, 0, 0, 1);  // Rojo para ERROR
			errorType = "[ERROR]: ";
			break;
		}

		// Recorrer cada mensaje en el vector de mensajes
		for (const auto& message : pair.second) {
			ImGui::PushStyleColor(ImGuiCol_Text, color);  // Establece el color
			ImGui::Text("%s", (errorType + message).c_str());  // Muestra el tipo de error y el mensaje
			ImGui::PopStyleColor();
		}
	}

	ImGui::End();
}

void 
	GUI::baseStyleGUI() {

	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	colors[ImGuiCol_Text] = ImVec4(0.80f, 0.70f, 0.60f, 1.00f);            // Color de texto (beige oscuro)
	colors[ImGuiCol_WindowBg] = ImVec4(0.20f, 0.15f, 0.10f, 1.00f);        // Fondo de ventana (marrón muy oscuro)
	colors[ImGuiCol_Button] = ImVec4(0.40f, 0.25f, 0.15f, 1.00f);          // Botones (marrón oscuro)
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.55f, 0.35f, 0.20f, 1.00f);   // Botones al pasar el mouse (marrón menos oscuro)
	colors[ImGuiCol_ButtonActive] = ImVec4(0.60f, 0.30f, 0.20f, 1.00f);    // Botones activos (marrón rojizo oscuro)
	colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.15f, 0.10f, 1.00f);         // Fondo de los frames (marrón muy oscuro)
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.35f, 0.20f, 0.15f, 1.00f);  // Fondo de los frames con hover (más claro)
	colors[ImGuiCol_TitleBg] = ImVec4(0.35f, 0.20f, 0.10f, 1.00f);         // Fondo del título (marrón oscuro)
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.45f, 0.30f, 0.15f, 1.00f);   // Fondo del título activo (marrón menos oscuro)

	colors[ImGuiCol_Border] = ImVec4(0.20f, 0.10f, 0.05f, 1.00f);          // Bordes (marrón muy oscuro)
	colors[ImGuiCol_CheckMark] = ImVec4(0.70f, 0.35f, 0.20f, 1.00f);       // Checkmark (marrón rojizo)
	colors[ImGuiCol_SliderGrab] = ImVec4(0.50f, 0.25f, 0.15f, 1.00f);      // Slider (marrón oscuro)
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.60f, 0.35f, 0.20f, 1.00f);// Slider activo (marrón menos oscuro)
	colors[ImGuiCol_Separator] = ImVec4(0.30f, 0.15f, 0.10f, 1.00f);       // Separadores (marrón muy oscuro)

	colors[ImGuiCol_Tab] = ImVec4(0.35f, 0.20f, 0.10f, 1.00f);             // Pestañas (marrón muy oscuro)
	colors[ImGuiCol_TabHovered] = ImVec4(0.50f, 0.30f, 0.20f, 1.00f);      // Pestañas al pasar el mouse (marrón menos oscuro)
	colors[ImGuiCol_TabActive] = ImVec4(0.55f, 0.30f, 0.20f, 1.00f);       // Pestañas activas (marrón oscuro)
	colors[ImGuiCol_Header] = ImVec4(0.30f, 0.15f, 0.10f, 1.00f);          // Encabezado (marrón oscuro)
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.40f, 0.25f, 0.15f, 1.00f);   // Encabezado al pasar el mouse (más claro)
	colors[ImGuiCol_HeaderActive] = ImVec4(0.50f, 0.30f, 0.20f, 1.00f);    // Encabezado activo (marrón cálido)

	colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.15f, 0.10f, 1.00f);         // Fondo de pop-ups (marrón oscuro)

	// Ajustes de estilo general
	style.WindowRounding = 5.0f;   // Redondeo de bordes de ventanas
	style.FrameRounding = 5.0f;   // Redondeo de bordes de cuadros
	style.ScrollbarRounding = 5.0f;   // Redondeo de bordes de scrollbar
	style.GrabRounding = 5.0f;   // Redondeo de bordes de botones de agarrar
	style.FrameBorderSize = 1.0f;   // Grosor del borde de cuadros
	style.WindowBorderSize = 1.0f;   // Grosor del borde de ventanas
	style.PopupBorderSize = 1.0f;   // Grosor del borde de popups

}