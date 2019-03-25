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
