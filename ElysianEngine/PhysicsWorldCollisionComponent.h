#pragma once
#include "GameObjectComponent.h"
#include "BoxColliderComponent.h"

class PhysicsWorldCollisionComponent : public GameObjectComponent
{
public:
	PhysicsWorldCollisionComponent(GameObject& parent, const std::string type);
	
	void UpdateState(const float deltaTime, Command* command) override;
	GameObjectComponent* Clone() const override;

	void RegisterNewCollider(class BoxColliderComponent* newCollider);

private:

	std::vector<class BoxColliderComponent*> _colliders;
};

