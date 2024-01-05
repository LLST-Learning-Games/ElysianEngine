#include "GameObject.h"
#include <iostream>

#pragma region INITIALIZATION
GameObject::GameObject(const std::string& id, Game& game) :
	_game(game),
	_id(id),
	_transform(nullptr)
{
	std::cout << "Constructing new " << _id << ".\n";

}

GameObject::~GameObject()
{
	std::cout << "Destroying " << _id << ".\n";
	_components.clear();
}

GameObject::GameObject(const GameObject& other) :
	_id(other._id),
	_game(other._game),
	_transform(nullptr)
{
	std::cout << "Calling copy constructor on " << _id << ".\n";
	for (auto &component : other._components) {
		TryAddComponent(component->Clone());
	}
}

GameObject::GameObject(GameObject&& other) noexcept :
	_id(other._id),
	_game(other._game)
{
	// todo - This move constructor breaks the _parent reference on the components!  
	//		  Need to decide if I will make _parent a pointer or remove this approach.
	
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

Game& GameObject::GetGame()
{
	return _game;
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
	_components.emplace_back(std::unique_ptr<GameObjectComponent>(component));
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

