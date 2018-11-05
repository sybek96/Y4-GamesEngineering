#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"
class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();
	void update();
	void addEntity(Entity e);

private:
	std::vector<Entity> m_entities;
	bool m_output;
};

