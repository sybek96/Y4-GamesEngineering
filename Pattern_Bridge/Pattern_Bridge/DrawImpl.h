#pragma once
#include "DrawAPI.h"
#include <iostream>

/// <summary>
/// The concrete implementation, inherits the base DrawAPI interface
/// </summary>
class DrawImpl :
	public DrawAPI
{
public:
	DrawImpl();
	~DrawImpl();
	void Draw() override;
};

