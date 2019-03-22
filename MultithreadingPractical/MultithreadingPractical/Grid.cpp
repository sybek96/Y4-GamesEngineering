#include "Grid.h"

Grid::Grid(int amountWide, int amountHigh)
{
	int amountOfCells = amountWide * amountHigh;
	int nodeSizeX = Screen::getWidth() / amountWide;
	int nodeSizeY = Screen::getHeight() / amountHigh;


	for (int i = 0; i < amountHigh * nodeSizeX; i+=nodeSizeX) //col
	{
		for (int j = 0; j < amountWide * nodeSizeY; j+=nodeSizeY) //row
		{
			nodes.push_back(std::make_unique<Node>(Vector2D(i, j), Vector2D(nodeSizeX, nodeSizeY)));
		}
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
}
