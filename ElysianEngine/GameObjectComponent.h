#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <SDL_stdinc.h>
#include "Command.h"

class GameObjectComponent
{
public:
	GameObjectComponent(class GameObject& parent, const std::string type, const int updateOrder = 100);

	int GetUpdateOrder();

	virtual void UpdateInput(const float deltaTime, const Uint8* keyboardState);
	virtual void UpdateState(const float deltaTime, Command* command);
	virtual void UpdateOutput(const float deltaTime);

	virtual GameObjectComponent* Clone() const = 0;
	
	const std::string& GetType() const;

protected:
	GameObject& _parent;
	const int _updateOrder;
	const std::string _type;
};

