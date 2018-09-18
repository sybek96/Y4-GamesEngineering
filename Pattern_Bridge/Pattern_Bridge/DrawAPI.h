#pragma once

/// <summary>
/// abstract of draw API.
/// </summary>
class DrawAPI
{
public:
	DrawAPI() {};
	~DrawAPI() {};
	virtual void Draw() = 0;
};

