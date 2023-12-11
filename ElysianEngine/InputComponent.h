#pragma once
#include "GameObject.h"
#include "GameObjectComponent.h"
#include "Vector2D.h"
#include "TransformComponent.h"

class InputComponent :
    public GameObjectComponent
{
public:
    InputComponent(const GameObject& parent);
    void UpdateInput(const float deltaTime, const Uint8* keyboardState) override;

    InputComponent* Clone() const override;

private:
    TransformComponent& _transform;
    Vector2D _directionalInput;
};