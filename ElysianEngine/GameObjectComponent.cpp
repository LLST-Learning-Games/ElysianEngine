#include "GameObjectComponent.h"

GameObjectComponent::GameObjectComponent(GameObject& parent, std::string type, int updateOrder) :
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

std::string GameObjectComponent::GetType()
{
	return _type;
}



