#include "GameObject.h"
#include <iostream>

#pragma region INITIALIZATION
GameObject::GameObject(std::string id, Game& game) :
	_game(game)
{
	SetId(id);
}

GameObject::~GameObject()
{
	for (auto component : _components) 
	{
		delete component;
	}
	_components.clear();
}

#pragma endregion

#pragma region CORE LOOP

void GameObject::UpdateInput(const float deltaTime, const Uint8* keyboardState)
{
	for (int i = 0; i < _components.size(); i++) {
		_components[i]->UpdateInput(deltaTime, keyboardState);
	}
}

void GameObject::UpdateState(const float deltaTime)
{
	for (int i = 0; i < _components.size(); i++) {
		_components[i]->UpdateState(deltaTime);
	}
}

void GameObject::UpdateOutput(const float deltaTime)
{
	for (int i = 0; i < _components.size(); i++) {
		_components[i]->UpdateOutput(deltaTime);
	}
}


#pragma endregion

#pragma region ACCESSORS 

std::string GameObject::GetId()
{
	return std::string();
}

void GameObject::SetId(std::string id)
{
	_id = id;
}

TransformComponent& GameObject::GetTransform()
{
	return *_transform;
}

bool GameObject::TryAddComponent(GameObjectComponent* component)
{
	_components.emplace_back(component);
	//_components.emplace_back(std::make_unique<GameObjectComponent>(*component));
	
	if (component->GetType() == "transform") {
		_transform = dynamic_cast<TransformComponent*>(component);
	}
	return true;
}

bool GameObject::TryRemoveComponent(GameObjectComponent& component)
{
	// todo
	return false;
}

#pragma endregion

