#include "CommandStream.h"

void CommandStream::RegisterCommand(std::string objectId, std::string componentId, class Command* command)
{
	_commandStream[objectId][componentId] = std::unique_ptr<Command>(command);
}

std::unordered_map<std::string, std::unique_ptr<Command>>* CommandStream::GetGameObjectCommandList(std::string objectId)
{
	if (_commandStream.find(objectId) != _commandStream.end())
		return &_commandStream[objectId];

	return nullptr;
}

void CommandStream::ClearCommands()
{
	// todo - move to object pool structure rather than allocate and deallocate
	_commandStream.clear();
}


