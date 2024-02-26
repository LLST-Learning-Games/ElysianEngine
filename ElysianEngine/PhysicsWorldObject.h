#pragma once
#include "GameObject.h"
#include "PhysicsWorldCollisionComponent.h"

class PhysicsWorldObject : public GameObject
{
public:
    PhysicsWorldObject(std::string id, class Game& game);
};

