#include "RegisterColliderWithPhysicsWorldCommand.h"

RegisterColliderWithPhysicsWorldCommand::RegisterColliderWithPhysicsWorldCommand(BoxColliderComponent* collider)
	: _colliderComponent(collider)
{
}

void RegisterColliderWithPhysicsWorldCommand::Execute(PhysicsWorldCollisionComponent& collisionHandlerComponent)
{
	collisionHandlerComponent.RegisterNewCollider(_colliderComponent);
}
