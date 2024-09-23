#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class
	ShapeFactory : public Component {
public:
	ShapeFactory() = default;
	virtual
	~ShapeFactory() = default;

	ShapeFactory(ShapeType shapeType) : m_shape(nullptr), m_shapeType(ShapeType::NONE), Component(ComponentType::SHAPE){}

	sf::Shape*
	createShape(ShapeType shapeType);

	void update(float detlatime) override {}

	void
		render(Window window) override {}

	sf::Shape* getShape() {
		return m_shape;
	}
private:

	ShapeType m_shapeType;
public:
	sf::Shape* m_shape;
};