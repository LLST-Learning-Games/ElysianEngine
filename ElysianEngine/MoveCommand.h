#pragma once
#include "Command.h"
#include "TransformComponent.h"

class MoveCommand : public Command
{
public:
    MoveCommand(class Vector2D movement);

    void Execute(class TransformComponent& transform);

private:
    Vector2D _movement;
};

