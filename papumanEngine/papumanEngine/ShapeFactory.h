#pragma once
#include "Prerequisites.h"
#include "Component.h"


class
	ShapeFactory : public Component {
public:
	ShapeFactory() = default;
	virtual
	~ShapeFactory() = default;

	ShapeFactory(ShapeType shapeType) : m_shapeType(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE){}
	createShape(m_shapeType);
	sf::Shape*
		createShape(ShapeType shapeType);
private:
	ShapeType m_shapeType;
	sf::Shape* m_shape;
};