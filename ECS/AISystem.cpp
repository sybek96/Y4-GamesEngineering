#include "AISystem.h"



AISystem::AISystem()
	: m_output(false)
{
}


AISystem::~AISystem()
{
}

void AISystem::addEntity(Entity e)
{
	m_entities.push_back(e);
}

void AISystem::update()
{
	if (m_output == false)
	{
		std::cout << "AI system update" << std::endl;

		for (auto entity : m_entities)
		{
			std::cout << "Updating AI of : " << entity.getName() << std::endl;
		}
		m_output = true;
	}
}
