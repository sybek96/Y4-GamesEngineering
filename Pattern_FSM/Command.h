#pragma once
#include "Character.h"

/// <summary>
/// The pure virtual command interface
/// 
/// </summary>
class Command
{
public:
	virtual void execute(Character& character) = 0;
	virtual void undo(Character& character) = 0;
};