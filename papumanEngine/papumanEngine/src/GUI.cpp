#include "GUI.H"
#include "Window.h"

void 
GUI::init() {
	baseStyleGUI();
}
void GUI::update() {

}

void GUI::render() {
	 
}

void GUI::destroy() {

}
void GUI::baseStyleGUI() {
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