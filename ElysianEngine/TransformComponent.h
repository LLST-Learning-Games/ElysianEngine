#pragma once
#include "GameObjectComponent.h"
#include "GameObject.h"
#include "Vector2D.h"
#include "MoveCommand.h"
#include <iostream>

class TransformComponent : public GameObjectComponent
{
public:
	TransformComponent(const Vector2D& position, const Vector2D& scale, const float rotation, GameObject& parent);
	TransformComponent(const Vector2D& position, const Vector2D& scale, GameObject& parent);
	TransformComponent(const Vector2D& position, const float rotation, GameObject& parent);
	TransformComponent(const Vector2D& position, GameObject& parent);

	const Vector2D& GetPosition() const;
	const Vector2D& GetScale() const;
	const float GetRotation() const;

	void SetPosition(const Vector2D& position);
	void SetScale(const Vector2D& scale);
	void SetRotation(const float rotation);
	void SetMovementThisFrame(const Vector2D& moveBy);

	void UpdateState(const float deltaTime, Command* command) override;

	TransformComponent* Clone() const override;

protected:
	Vector2D _position;
	Vector2D _scale;
	float _rotation;

	const Vector2D* _movementThisFrame;
};

