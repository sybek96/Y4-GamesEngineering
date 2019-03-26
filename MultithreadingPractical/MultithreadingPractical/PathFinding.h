#ifndef _PATHFINDING_H
#define _PATHFINDING_H

#include "Grid.h"
#include <queue>
#include <limits>

class PathFinding {
public:
	PathFinding(std::shared_ptr<Grid> grid);
	std::vector<Vector2D> findPath(std::shared_ptr<Node> start, std::shared_ptr<Node> finish);

private:
	std::shared_ptr<Grid> m_grid;
};

#endif // !_PATHFINDING_H
