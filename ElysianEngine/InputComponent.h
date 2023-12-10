#pragma once
#include "GameObject.h"
#include "GameObjectComponent.h"
#include "Vector2D.h"
#include "TransformComponent.h"

class InputComponent :
    public GameObjectComponent
{
public:
    InputComponent(GameObject& parent);
    void UpdateInput(const float deltaTime, const Uint8* keyboardState) override;

private:
    TransformComponent& _transform;
};