#pragma once
#include "GameObjectComponent.h"
#include "TransformComponent.h"
#include "Vector2D.h"

class BoxColliderComponent :
    public GameObjectComponent
{
public:
    BoxColliderComponent(GameObject& parent, const Vector2D& size);
    const bool IntersectsWith(const BoxColliderComponent& otherBox) const;

    BoxColliderComponent* Clone() const override;

private:
    Vector2D _size;
};

