#include "GameObjectComponent.h"

GameObjectComponent::GameObjectComponent(const GameObject& parent, const std::string type, const int updateOrder) :
	_parent(parent),
	_type(type),
	_updateOrder(updateOrder)
{
	// todo - remove parent assignment from constructor and add to TryAddComponent.
	// ..
}

int GameObjectComponent::GetUpdateOrder()
{
	return _updateOrder;
}

void GameObjectComponent::UpdateInput(const float deltaTime, const Uint8* keyboardState)
{
}

void GameObjectComponent::UpdateState(const float deltaTime)
{
}

void GameObjectComponent::UpdateOutput(const float deltaTime)
{
}

const std::string& GameObjectComponent::GetType() const
{
	return _type;
}



