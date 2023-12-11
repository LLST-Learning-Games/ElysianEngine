#pragma once

#include "Game.h"

#include "GameObjectComponent.h"
#include "TransformComponent.h"
#include <vector>
#include <string>
#include <SDL.h>

class GameObject
{
public:
	GameObject(const std::string& id, const class Game& game);
	~GameObject();

	void UpdateInput(const float deltaTime, const Uint8* keyboardState);
	void UpdateState(const float deltaTime);
	void UpdateOutput(const float deltaTime);

	const bool TryAddComponent(class GameObjectComponent* component);
	const bool TryRemoveComponent(class GameObjectComponent& component);

	// todo - add update order to GameObject class

	const std::string& GetId() const;

	class TransformComponent& GetTransform() const;


private:
	const Game& _game;

	class TransformComponent* _transform;

	// todo - migrate to unique_ptr
	std::vector<GameObjectComponent*> _components;
	const std::string _id;
};

