#include "PhysicsWorldObject.h"

PhysicsWorldObject::PhysicsWorldObject(std::string id, Game& game) : GameObject(id, game)
{
	PhysicsWorldCollisionComponent* collisionHandler = new PhysicsWorldCollisionComponent(*this, "PhysicsWorldCollisionHandler");
	TryAddComponent(collisionHandler);
}
