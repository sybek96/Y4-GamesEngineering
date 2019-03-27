#include "PathFinding.h"

PathFinding::PathFinding(std::shared_ptr<Grid> grid)
	: m_grid(grid)
{
}

std::vector<Vector2D> PathFinding::findPath(std::shared_ptr<Node> start, std::shared_ptr<Node> finish)
{

	//pathToGoal.push_back(finish->getPosition());
	//return pathToGoal;
	std::vector<Vector2D> path;
	//Create priority queue
	//auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };

	auto lambdaComparator = [](const std::shared_ptr<Node>& left, const std::shared_ptr<Node>& right) {return (left->getH() > right->getH()); };
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, decltype(lambdaComparator)> pq(lambdaComparator);
	bool reachedGoal = false;

	for (auto& node : m_grid->getNodes())
	{
		//Only do if its not an obstacle
		if (!node->isBlocked())
		{
			node->setG(999999);
			node->setH(999999);
			node->setParent(nullptr); //Reset previous ptr
			node->setVisited(false); //Set visited to false
		}
	}
	start->setH(finish->getPosition().Distance(start->getPosition()));
	start->setG(0);
	start->setVisited(true);

	pq.push(start);

	//Keep searchign while our queue is not empty
	while (!pq.empty() && !reachedGoal)
	{
		auto current = pq.top(); //Get the value on the tope of the queue
		pq.pop();
		current->setVisited(true);
		//If we found the goal
		if (current->getID() == finish->getID())
		{
			reachedGoal = true;
			auto prev = current;
			while (nullptr != prev && prev->getParent())
			{
				path.push_back(prev->getPosition());
				prev = prev->getParent();
			}
			std::reverse(path.begin(), path.end());
			break;
		}

		//Loop through neighbours
		for (auto& node : current->m_adjecancySet)
		{
			//If the node is a wall or its closed skip it
			if (node->isBlocked() || node->isVisited())
			{
				continue;
			}

			auto newG = current->getG() + 1.0f;
			auto newH = node->getPosition().Distance(finish->getPosition());
			auto newF = newG + newH;

			//If we found a better path
			if (!node->isVisited() || node->getF() > newF)
			{
				node->setG(newG);
				node->setH(newH);
				node->setParent(current);

				//Only push it to the heap if it hasnt been visited yet
				if (!node->isVisited())
				{
					pq.push(node);
					node->setVisited(true);
				}
			}
		}
		////Remove from the top of the queue
		//pq.pop();

	}

	return path;
}

