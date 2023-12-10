#include "TransformComponent.h"

TransformComponent::TransformComponent(Vector2D& position, Vector2D& scale, float rotation, GameObject& parent) 
	: GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(rotation),
	_scale(scale),
	_movementThisFrame()
{
}

TransformComponent::TransformComponent(Vector2D& position, Vector2D& scale, GameObject& parent) 
	: GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(0.0f),
	_scale(scale),
	_movementThisFrame()
{
	
}

TransformComponent::TransformComponent(Vector2D& position, float rotation, GameObject& parent) 
	: GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(rotation),
	_scale(Vector2D(1.0f,1.0f)),
	_movementThisFrame()
{

}

TransformComponent::TransformComponent(Vector2D& position, GameObject& parent) 
	:GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(0.0f),
	_scale(Vector2D(1.0f, 1.0f)),
	_movementThisFrame()
{
	
}

Vector2D& TransformComponent::GetPosition()
{
	return _position;
}

Vector2D& TransformComponent::GetScale()
{
	return _scale;
}

float TransformComponent::GetRotation()
{
	return _rotation;
}

void TransformComponent::SetPosition(Vector2D& position)
{
	_position = position;
}

void TransformComponent::SetScale(Vector2D& scale)
{
	_scale = scale;
}

void TransformComponent::SetRotation(float rotation)
{
	_rotation = rotation;
}

void TransformComponent::SetMovementThisFrame(Vector2D* moveBy)
{
	_movementThisFrame = moveBy;
}

void TransformComponent::UpdateState(const float deltaTime)
{
	if (_movementThisFrame == nullptr) return;

	_position = _position + *_movementThisFrame;
	delete _movementThisFrame;
}
