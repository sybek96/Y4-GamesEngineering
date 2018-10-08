#pragma once
#include "Command.h"

/// <summary>
/// Shield command is a concrete command for calling a characters shield method.
/// </summary>
class ShieldCommand : public Command
{
public:
	virtual void execute(Character& character) { character.shield(); }
	virtual void undo(Character& character) override { std::cout << "Undone the command: " << std::endl; character.shield(); }
};
