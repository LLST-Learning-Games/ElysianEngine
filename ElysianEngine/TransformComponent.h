#pragma once
#include "GameObjectComponent.h"
#include "GameObject.h"
#include "Vector2D.h"
#include <iostream>

class TransformComponent : public GameObjectComponent
{
public:
	TransformComponent(Vector2D& position, Vector2D& scale, float rotation, GameObject& parent);
	TransformComponent(Vector2D& position, Vector2D& scale, GameObject& parent);
	TransformComponent(Vector2D& position, float rotation, GameObject& parent);
	TransformComponent(Vector2D& position, GameObject& parent);

	Vector2D& GetPosition();
	Vector2D& GetScale();
	float GetRotation();

	void SetPosition(Vector2D& position);
	void SetScale(Vector2D& scale);
	void SetRotation(float rotation);
	void SetMovementThisFrame(Vector2D* moveBy);

	void UpdateState(const float deltaTime) override;

protected:
	Vector2D _position;
	Vector2D _scale;
	float _rotation;

	Vector2D* _movementThisFrame;
};

