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

	GameObject(const GameObject& other);
	GameObject(GameObject&& other) noexcept;
	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) noexcept = delete;


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
	const std::string _id;
	std::vector<std::unique_ptr<GameObjectComponent>> _components;
	class TransformComponent* _transform;
};

