#include "MoveCommand.h"

MoveCommand::MoveCommand(Vector2D movement) :
	_movement(movement)
{
}

void MoveCommand::Execute(TransformComponent& transform)
{
	transform.SetMovementThisFrame(_movement);
}
