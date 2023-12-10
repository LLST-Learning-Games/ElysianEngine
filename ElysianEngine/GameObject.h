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
	GameObject(std::string id, class Game& game);
	~GameObject();

	void UpdateInput(const float deltaTime, const Uint8* keyboardState);
	void UpdateState(const float deltaTime);
	void UpdateOutput(const float deltaTime);

	bool TryAddComponent(class GameObjectComponent* component);
	bool TryRemoveComponent(class GameObjectComponent& component);

	// todo - add update order to GameObject class

	std::string GetId();
	void SetId(std::string id);

	class TransformComponent& GetTransform();


private:
	Game& _game;

	class TransformComponent* _transform;

	// todo - migrate to unique_ptr
	std::vector<GameObjectComponent*> _components;
	std::string _id;
};

