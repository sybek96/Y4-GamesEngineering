#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"
class AISystem
{
public:
	AISystem();
	~AISystem();
	void addEntity(Entity e);
	void update();
private:
	std::vector<Entity> m_entities;
	bool m_output;
};

