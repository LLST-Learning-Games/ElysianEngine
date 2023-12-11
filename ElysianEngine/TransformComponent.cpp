#include "TransformComponent.h"

TransformComponent::TransformComponent(const Vector2D& position, const Vector2D& scale, const float rotation, const GameObject& parent) 
	: GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(rotation),
	_scale(scale),
	_movementThisFrame()
{
}

TransformComponent::TransformComponent(const Vector2D& position, const Vector2D& scale, const GameObject& parent) 
	: GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(0.0f),
	_scale(scale),
	_movementThisFrame()
{
	
}

TransformComponent::TransformComponent(const Vector2D& position, const float rotation, const GameObject& parent) 
	: GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(rotation),
	_scale(Vector2D(1.0f,1.0f)),
	_movementThisFrame()
{

}

TransformComponent::TransformComponent(const Vector2D& position, const GameObject& parent) 
	:GameObjectComponent(parent, "transform"),
	_position(position),
	_rotation(0.0f),
	_scale(Vector2D(1.0f, 1.0f)),
	_movementThisFrame()
{
	
}

const Vector2D& TransformComponent::GetPosition() const
{
	return _position;
}

const Vector2D& TransformComponent::GetScale() const
{
	return _scale;
}

const float TransformComponent::GetRotation() const
{
	return _rotation;
}

void TransformComponent::SetPosition(const Vector2D& position)
{
	_position = position;
}

void TransformComponent::SetScale(const Vector2D& scale)
{
	_scale = scale;
}

void TransformComponent::SetRotation(const float rotation)
{
	_rotation = rotation;
}

void TransformComponent::SetMovementThisFrame(const Vector2D& moveBy)
{
	_movementThisFrame = &moveBy;
}

void TransformComponent::UpdateState(const float deltaTime)
{
	if (_movementThisFrame == nullptr) return;

	_position = _position + *_movementThisFrame;
}

TransformComponent* TransformComponent::Clone() const
{
	return nullptr;
}
