#include "PhysicsWorldCollisionComponent.h"

PhysicsWorldCollisionComponent::PhysicsWorldCollisionComponent(GameObject& parent, const std::string type)
    : GameObjectComponent(parent,type)
{

}

GameObjectComponent* PhysicsWorldCollisionComponent::Clone() const
{
    return nullptr;
}

void PhysicsWorldCollisionComponent::RegisterNewCollider(BoxColliderComponent* newCollider)
{
    _colliders.push_back(newCollider);
}


void PhysicsWorldCollisionComponent::UpdateState(const float deltaTime, Command* command)
{
	if (command == nullptr) return;

	RegisterColliderWithPhysicsWorldCommand* registerCommand = (RegisterColliderWithPhysicsWorldCommand*)command;

	if (registerCommand == nullptr) return;

	registerCommand->Execute(*this);
}
