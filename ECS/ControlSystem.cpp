#include "ControlSystem.h"



ControlSystem::ControlSystem()
	: m_output(false)
{
}


ControlSystem::~ControlSystem()
{
}

void ControlSystem::update()
{
	if (m_output == false)
	{
		std::cout << "control system update" << std::endl;

		for (auto entity : m_entities)
		{
			std::cout << "Updating control of : " << entity.getName() << std::endl;
		}
		m_output = true;
	}
}

void ControlSystem::addEntity(Entity e)
{
	m_entities.push_back(e);
}
