#pragma once
#include "GameObjectComponent.h"
#include "TransformComponent.h"
#include "Vector2D.h"

class BoxColliderComponent :
    public GameObjectComponent
{
public:
    BoxColliderComponent(GameObject& parent, Vector2D& size);
    bool IntersectsWith(const BoxColliderComponent& otherBox);

private:
    Vector2D _size;
};

