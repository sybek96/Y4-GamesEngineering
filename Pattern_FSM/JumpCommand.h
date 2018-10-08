#pragma once
#include "Command.h"

/// <summary>
/// Jump command is a concrete command for calling a characters jump method.
/// </summary>
class JumpCommand : public Command
{
public:
	virtual void execute(Character& character) { character.jump(); }
	virtual void undo(Character& character) override { std::cout << "Undone the command: " << std::endl; character.jump(); }

};

