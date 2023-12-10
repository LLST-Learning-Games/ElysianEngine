#pragma once
#include "Vector2D.h"
#include "SpriteComponent.h"
#include "AnimatedSpriteComponent.h"
#include "DataLibrary.h"

class UfoObject : public GameObject
{
public:
    UfoObject(std::string id, class Game& game);
};

