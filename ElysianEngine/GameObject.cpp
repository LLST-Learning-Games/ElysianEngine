#include "GameObject.h"
#include <iostream>

#pragma region INITIALIZATION
GameObject::GameObject(const std::string& id, const Game& game) :
	_game(game),
	_id(id)
{
}

GameObject::~GameObject()
{
	for (auto component : _components) 
	{
		delete component;
	}
	_components.clear();
}

GameObject::GameObject(const GameObject& other) :
	_id(other._id),
	_game(other._game)
{
	std::cout << "Calling copy constructor on " << _id;
}

GameObject::GameObject(GameObject&& other) noexcept :
	_id(other._id),
	_game(other._game)
{
	_components = std::move(other._components);
	_transform = other._transform;
	other._transform = nullptr;
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

const std::string& GameObject::GetId() const
{
	return std::string();
}

TransformComponent& GameObject::GetTransform() const
{
	return *_transform;
}

const bool GameObject::TryAddComponent(GameObjectComponent* component)
{
	_components.emplace_back(component);
	//_components.emplace_back(std::make_unique<GameObjectComponent>(*component));
	
	if (component->GetType() == "transform") {
		_transform = dynamic_cast<TransformComponent*>(component);
	}
	return true;
}

const bool GameObject::TryRemoveComponent(GameObjectComponent& component)
{
	// todo
	return false;
}

#pragma endregion

