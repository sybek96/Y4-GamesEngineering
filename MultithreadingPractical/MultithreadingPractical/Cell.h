#ifndef _CELL_H
#define _CELL_H

#define NOMINMAX
#define WORLD_SIZE 3

#include <numeric>
#include <vector>
#include "SDL.h"
#include "Vector2D.h"
//3 x 3 = 9 for debugging

class Cell {
public:
	Cell();
	void draw(SDL_Renderer* renderer);
	Vector2D coordinates;
	int m_id;
	Cell* parent;
	float G; //accumulated distance from start node
	int H = std::numeric_limits<int>::max(); //heuristic to goal set to int numeric limit
	bool blocked = false;
	bool isStart = false;
	bool visited = false;
	std::vector<Cell*> adjecancySet;
	Cell() : parent(0) {};
	Cell(int x, int y, Cell* _parent = 0) 
		: parent(_parent)
		, m_id(x * WORLD_SIZE + y)
		, G(0)
		, H(0) 
	{
		coordinates.x = x;
		coordinates.y = y;
	};

	//G + H
	float getF() { return G + H; }

	float manhattanDist(Cell* endCell)
	{
		float x = static_cast<float>(fabs(this->coordinates.x - static_cast<float>(endCell->coordinates.x)));
		float y = static_cast<float>(fabs(this->coordinates.y - static_cast<float>(endCell->coordinates.y)));
		return x + y;
	}
};

#endif // !_CELL_H
