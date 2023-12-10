#include "BoxColliderComponent.h"

BoxColliderComponent::BoxColliderComponent(GameObject& parent, Vector2D& size)
	: GameObjectComponent(parent, "boxCollider"),
	_size(size)
{
}

bool BoxColliderComponent::IntersectsWith(const BoxColliderComponent& otherBox)
{
	return false;
}
