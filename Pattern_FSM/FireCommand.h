#pragma once
#include "Command.h"

/// <summary>
/// Fire command is a concrete command for calling a characters fire method.
/// </summary>
class FireCommand : public Command
{
public:
	virtual void execute(Character& character) { character.fire(); }
	virtual void undo(Character& character) override { std::cout << "Undone the command: " << std::endl; character.fire(); }
};
