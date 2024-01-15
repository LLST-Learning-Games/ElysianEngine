#pragma once
#include <string>

class Command
{
public:
	virtual void Execute(class GameObjectComponent& _component);
};

