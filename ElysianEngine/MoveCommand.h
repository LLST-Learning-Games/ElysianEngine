#pragma once
#include "Command.h"
#include "TransformComponent.h"

class MoveCommand : public Command
{
public:
    MoveCommand(Vector2D movement);

    void Execute(TransformComponent& transform);

private:
    Vector2D _movement;
};

