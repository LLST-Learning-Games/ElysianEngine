#include "InputComponent.h"


InputComponent::InputComponent(GameObject& parent)
	: GameObjectComponent(parent, "input"),
	_transform(parent.GetTransform())
{
}

void InputComponent::UpdateInput(const float deltaTime, const Uint8* keyboardState)
{
	Vector2D* movement = new Vector2D(0, 0);

	if (keyboardState[SDL_SCANCODE_UP]) {
		movement->y -= 5;
	}
	if (keyboardState[SDL_SCANCODE_DOWN]) {
		movement->y += 5;
	}
	if (keyboardState[SDL_SCANCODE_LEFT]) {
		movement->x -= 5;
	}
	if (keyboardState[SDL_SCANCODE_RIGHT]) {
		movement->x += 5;
	}

	_transform.SetMovementThisFrame(movement);
}
