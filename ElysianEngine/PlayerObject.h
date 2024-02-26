#pragma once
#include "GameObject.h"
#include "SpriteComponent.h"
#include "AnimatedSpriteComponent.h"
#include "InputComponent.h"
#include "BoxColliderComponent.h"

#include "DataLibrary.h"

class PlayerObject :
    public GameObject
{
public:
    PlayerObject(std::string id, class Game& game);
};

