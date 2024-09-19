#include "Actor.h"


Actor::Actor(std::string actorName) {
	//Setup actorName
	m_name = actorName;
	//Setup Transform

	//SetupShape
	EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();{
		addComponent(shape);
	}

}