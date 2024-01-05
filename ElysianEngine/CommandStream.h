#pragma once
#include <unordered_map>
#include <memory>
#include "Command.h"

class CommandStream
{
public:
	void RegisterCommand(std::string objectId, std::string componentId, Command* command);
	std::unordered_map<std::string, std::unique_ptr<Command>>* GetGameObjectCommandList(std::string objectId);

private:
	std::unordered_map<std::string,	std::unordered_map<std::string, std::unique_ptr<Command>>> _commandStream;
};

