#include "BoxColliderComponent.h"

BoxColliderComponent::BoxColliderComponent(GameObject& parent, const Vector2D& size)
	: GameObjectComponent(parent, "boxCollider"),
	_size(size)
{
	RegisterColliderWithPhysicsWorldCommand* command = new RegisterColliderWithPhysicsWorldCommand(this);
	_parent.GetGame().GetCommandStream().RegisterCommand("physicsWorld", "PhysicsWorldCollisionHandler", command);
}

const bool BoxColliderComponent::IntersectsWith(const BoxColliderComponent& otherBox) const
{
	return false;
}

BoxColliderComponent* BoxColliderComponent::Clone() const
{
	return nullptr;
}
