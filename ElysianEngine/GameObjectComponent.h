#pragma once
#include <string>
#include <SDL_stdinc.h>

class GameObjectComponent
{
public:
	GameObjectComponent(class GameObject& parent, std::string type, int updateOrder = 100);

	int GetUpdateOrder();

	virtual void UpdateInput(const float deltaTime, const Uint8* keyboardState);
	virtual void UpdateState(const float deltaTime);
	virtual void UpdateOutput(const float deltaTime);

	std::string GetType();

protected:
	class GameObject& _parent;
	int _updateOrder;
	std::string _type;
};

