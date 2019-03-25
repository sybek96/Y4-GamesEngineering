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
			nodes.push_back(std::make_unique<Node>(Vector2D(i, j), Vector2D(nodeSizeX, nodeSizeY), idCounter));
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

void Grid::calculateAdjecencySet()
{
	//for (int i = 0; i < m_openList.size(); i++)
	//{
	//	auto currentCell = m_openList[i];
	//	currentCell->adjecancySet.clear();
	//	int x = currentCell->m_xCoord;
	//	int y = currentCell->m_yCoord;


	//	if (x < max_grid_size) //if x less than last square next one is neighbor RIGHT
	//	{
	//		if (!m_openList[i + right]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + right]);
	//		}
	//	}
	//	if (x > 0) // if x more than zero previous is neighbor LEFT
	//	{
	//		if (!m_openList[i + left]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + left]);
	//		}
	//	}
	//	if (y > 0) // if y greater than 0 TOP
	//	{
	//		if (!m_openList[i + up]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + up]);
	//		}
	//	}
	//	if (y < max_grid_size) // if y less tham max height BOTTOM
	//	{
	//		if (!m_openList[i + bottom]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + bottom]);
	//		}
	//	}
	//	if (x < max_grid_size && y > 0) // TOP RIGHT
	//	{
	//		if (!m_openList[i + top_right]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + top_right]);
	//		}
	//	}
	//	if (y < max_grid_size && x < max_grid_size) // BOTTOM RIGHT
	//	{
	//		if (!m_openList[i + bottom_right]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + bottom_right]);
	//		}
	//	}
	//	if (y < max_grid_size && x > 0) //BOTTOM LEFT
	//	{
	//		if (!m_openList[i + bottom_left]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + bottom_left]);
	//		}
	//	}
	//	if (y > 0 && x > 0) // TOP LEFT
	//	{
	//		if (!m_openList[i + top_left]->blocked)
	//		{
	//			currentCell->adjecancySet.push_back(m_openList[i + top_left]);
	//		}
	//	}
	//}
	for (int i = 0; i <= nodes.size(); i++)
	{
		auto& currentCell = nodes.at(i);
		currentCell->m_adjecancySet.clear();

		if (currentCell->getID() < m_maxGridSize - gridHeight) //if can check right cell
		{

		}

	}
}
