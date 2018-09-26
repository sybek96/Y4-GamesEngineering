#pragma once
#include "Command.h"

/// <summary>
/// Melee command is a concrete command for calling a characters melee method.
/// </summary>
class MeleeCommand : public Command
{
public:
	virtual void execute(Character& character) { character.melee(); }
	virtual void undo(Character& character) override { std::cout << "Undone the command: " << std::endl; character.crouch(); }
};
