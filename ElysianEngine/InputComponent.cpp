#include "InputComponent.h"


InputComponent::InputComponent(const GameObject& parent)
	: GameObjectComponent(parent, "input"),
	_transform(parent.GetTransform())
{
}

void InputComponent::UpdateInput(const float deltaTime, const Uint8* keyboardState)
{
	_directionalInput.x = 0;
	_directionalInput.y = 0;

	if (keyboardState[SDL_SCANCODE_UP]) {
		_directionalInput.y -= 5;
	}
	if (keyboardState[SDL_SCANCODE_DOWN]) {
		_directionalInput.y += 5;
	}
	if (keyboardState[SDL_SCANCODE_LEFT]) {
		_directionalInput.x -= 5;
	}
	if (keyboardState[SDL_SCANCODE_RIGHT]) {
		_directionalInput.x += 5;
	}

	_transform.SetMovementThisFrame(_directionalInput);
}

InputComponent* InputComponent::Clone() const
{
	return new InputComponent(_parent);
}
