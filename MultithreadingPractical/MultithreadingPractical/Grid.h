#ifndef _GRID_H
#define _GRID_H

#include <memory>
#include "Node.h"
#include "Screen.h"

class Grid {
public:
	Grid() = default;
	Grid(int amountWide, int amountHigh);
	void draw(SDL_Renderer* renderer);
private:
	std::vector<std::unique_ptr<Node>> nodes;
};

#endif // !_GRID_H
