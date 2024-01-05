#pragma once
#include <string>
#include "GameObjectComponent.h"

class Command
{
public:
	virtual void Execute(GameObjectComponent& _component);
};

