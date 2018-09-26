#pragma once
#include "Command.h"

/// <summary>
/// Crouch command is a concrete command for calling a characters crouch method.
/// </summary>
class CrouchCommand : public Command
{
public:
	virtual void execute(Character& character) override { character.crouch(); }
	virtual void undo(Character& character) override { std::cout << "Undone the command: " << std::endl; character.crouch(); }
};
