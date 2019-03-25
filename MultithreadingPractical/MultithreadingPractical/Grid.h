#ifndef _GRID_H
#define _GRID_H

#include <memory>
#include "Node.h"
#include "Screen.h"
#include "Line.h"

class Grid {
public:
	Grid() = default;
	Grid(int amountWide, int amountHigh);
#pragma region Copy/move constructors
	Grid(Grid const &) = default;
	Grid & operator=(Grid const &) = default;

	Grid(Grid &&) = default;
	Grid & operator=(Grid &&) = default;

#pragma endregion
#pragma region Getters/Setters
	std::vector<std::unique_ptr<Node>>& getNodes() { return nodes; }
	const int& getGridHeight() { return gridHeight; }
#pragma endregion

	void draw(SDL_Renderer* renderer);
	void calculateAdjecencySet();
private:
	std::vector<std::unique_ptr<Node>> nodes;
	std::vector<std::unique_ptr<Line>> lines;
	int gridHeight;

	int m_maxGridSize;
	int m_up;
	int m_right;
	int m_bottom;
	int m_left;
};

#endif // !_GRID_H
