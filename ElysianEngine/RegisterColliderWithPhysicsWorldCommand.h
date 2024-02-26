#pragma once
#include "Command.h"
#include "BoxColliderComponent.h"
#include "PhysicsWorldCollisionComponent.h"

class RegisterColliderWithPhysicsWorldCommand : public Command
{
public:
    RegisterColliderWithPhysicsWorldCommand(class BoxColliderComponent* collider);
    void Execute(class PhysicsWorldCollisionComponent& collisionComponent);

private:
    class BoxColliderComponent* _colliderComponent;
};

