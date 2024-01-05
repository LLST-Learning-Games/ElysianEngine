#include "InputComponent.h"


InputComponent::InputComponent(GameObject& parent)
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

	MoveCommand* command = new MoveCommand(_directionalInput);
	_parent.GetGame().GetCommandStream().RegisterCommand(_parent.GetId(),"transform",command);
}

InputComponent* InputComponent::Clone() const
{
	return new InputComponent(_parent);
}
