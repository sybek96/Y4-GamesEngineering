#include "RenderSystem.h"



RenderSystem::RenderSystem()
	: m_output(false)
{
}


RenderSystem::~RenderSystem()
{
}

void RenderSystem::update()
{
	if (m_output == false)
	{
		std::cout << "Render system update" << std::endl;

		for (auto entity : m_entities)
		{
			std::cout << "Updating Render of : " << entity.getName() << std::endl;
		}
		m_output = true;
	}
}

void RenderSystem::addEntity(Entity e)
{
	m_entities.push_back(e);
}
