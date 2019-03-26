#include "Grid.h"

Grid::Grid(int amountWide, int amountHigh)
	: gridHeight(amountHigh)
{
	int amountOfCells = amountWide * amountHigh;
	int nodeSizeX = Screen::getWidth() / amountWide;
	int nodeSizeY = Screen::getHeight() / amountHigh;

	int idCounter = 0;
	for (int i = 0; i < amountHigh * nodeSizeX; i+=nodeSizeX) //col
	{
		for (int j = 0; j < amountWide * nodeSizeY; j+=nodeSizeY) //row
		{
			nodes.push_back(std::make_shared<Node>(Vector2D(i, j), Vector2D(nodeSizeX, nodeSizeY), idCounter));
			idCounter++;
		}
	}

	for (int i = nodeSizeX; i < amountWide * nodeSizeX; i += nodeSizeX) //col
	{
		lines.push_back(std::make_unique<Line>(Vector2D(i, 0), Vector2D(i, Screen::getHeight())));
	}

	for (int i = nodeSizeY; i < amountHigh * nodeSizeY; i += nodeSizeY) //col
	{
		lines.push_back(std::make_unique<Line>(Vector2D(0, i), Vector2D(Screen::getWidth(), i)));
	}
	m_maxGridSize = amountOfCells;
	m_up = -1;
	m_right = amountHigh;
	m_bottom = 1;
	m_left = -amountHigh;
	//setting color of a line (wall)
	/*for (int i = 100; i < 170; i++)
	{
		nodes.at(i)->setRGBA(0, 0, 0);
	}*/
	calculateAdjecencySet();
}

void Grid::draw(SDL_Renderer * renderer)
{
	for (auto& node : nodes)
	{
		node->draw(renderer);
	}
	for (auto& line : lines)
	{
		line->draw(renderer);
	}
}

/// <summary>
/// Calculate the adjecency set.
/// This means all neighboring nodes that are not blocked.
/// </summary>
void Grid::calculateAdjecencySet()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		auto& currentCell = nodes.at(i);
		currentCell->m_adjecancySet.clear();
		auto currentID = currentCell->getID();
		if ((currentID < m_maxGridSize - gridHeight) && (!nodes.at(currentID + gridHeight)->isBlocked())) //if can check right cell
		{
			currentCell->m_adjecancySet.push_back(nodes.at(currentID + gridHeight));
		}
		//check above cell
		if (currentID != 0 && !nodes.at(currentID - 1)->isBlocked() && nodes.at(currentID - 1)->getPosition().y < currentCell->getPosition().y)
		{
			currentCell->m_adjecancySet.push_back(nodes.at(currentID - 1));
		}
		//check left cell
		if (currentID - gridHeight >= 0 && !nodes.at(currentID - gridHeight)->isBlocked())
		{
			currentCell->m_adjecancySet.push_back(nodes.at(currentID - gridHeight));
		}
		//check below cell
		if (currentID != (m_maxGridSize - 1) && !nodes.at(currentID + 1)->isBlocked() && nodes.at(currentID + 1)->getPosition().y > currentCell->getPosition().y)
		{
			currentCell->m_adjecancySet.push_back(nodes.at(currentID + 1));
		}
	}
}
