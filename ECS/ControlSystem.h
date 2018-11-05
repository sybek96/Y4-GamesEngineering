#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"
class ControlSystem
{
public:
	ControlSystem();
	~ControlSystem();
	void update();
	void addEntity(Entity e);
private:
	bool m_output;
	std::vector<Entity> m_entities;
};

