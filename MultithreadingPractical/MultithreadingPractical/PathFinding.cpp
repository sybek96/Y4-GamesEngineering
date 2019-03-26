#include "PathFinding.h"

PathFinding::PathFinding(std::shared_ptr<Grid> grid)
	: m_grid(grid)
{
}

std::vector<Vector2D> PathFinding::findPath(std::shared_ptr<Node> start, std::shared_ptr<Node> finish)
{
	//for (auto& node : m_grid->getNodes())
	//{
	//	node->setVisited(false);
	//	node->setParent(nullptr);
	//}

	////generate priority queue with greater node predicate
	//std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, Node::GreaterThanNode> pq;
	//start->setG(0);
	//start->setParent(nullptr);
	//int costSoFar = 0;


	////add start node to queue
	//pq.push(start);
	//auto current = pq.top();

	//while (!pq.empty())
	//{
	//	pq.pop();

	//	//if current node is the goal exit
	//	if (current->getID() == finish->getID())
	//	{
	//		break;
	//	}
	//	//go through adjecency set of top node in queue
	//	for (auto& neighborNode : current->m_adjecancySet)
	//	{
	//		if (!neighborNode->isVisited())
	//		{
	//			neighborNode->setVisited(true);
	//			neighborNode->setG(current->getG() + 1); //previous distance + 1
	//			pq.push(neighborNode);
	//		}

	//	}
	//	if (!pq.empty())
	//	{
	//		current = pq.top();
	//	}

	//}
	//auto finishPos = finish->getPosition();
	////set heuristic to goal for all cells
	//for (auto node : m_grid->getNodes())
	//{
	//	//set goals heuristic to 0
	//	if (node->getID() == finish->getID())
	//	{
	//		node->setH(0);
	//	}
	//	auto vecToGoal = finishPos - node->getPosition();
	//	node->setH(vecToGoal.Length() / 20);
	//}
	////do a star checks
	//for (auto& childCell = start; !(childCell->getID() == finish->getID()); childCell = childCell->getParent())
	//{
	//	for (auto& childCellNeighbor : childCell->m_adjecancySet)
	//	{
	//		if (childCell->getParent() == nullptr || costSoFar > childCell->getF() + childCellNeighbor->getF())
	//		{
	//			costSoFar += childCellNeighbor->getF();
	//			childCell->setParent(childCellNeighbor);
	//		}
	//	}
	//}

	//std::vector<Vector2D> pathToGoal;
	//pathToGoal.reserve(10000);
	//for (auto i = finish; nullptr == i;)
	//{
	//	if (nullptr != i)
	//	{
	//		pathToGoal.push_back(i->getPosition());
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}

	//pathToGoal.push_back(finish->getPosition());
	//return pathToGoal;
	bool foundPath = false;
	std::vector<Vector2D> path;
	//Create priority queue
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, Node::GreaterThanNode> pq;

	for (auto& node : m_grid->getNodes())
	{
		auto& t = node;
		//Only do if its not an obstacle
		if (!t->isBlocked())
		{
			t->setG(999999);
			t->setH(999999);
			t->setParent(nullptr); //Reset previous ptr
			t->setVisited(false); //Set visited to false
		}
	}
	start->setH(finish->getPosition().Distance(start->getPosition()));
	start->setG(0);
	start->setVisited(true);

	pq.push(start);

	//Keep searchign while our queue is not empty
	while (!pq.empty() && !foundPath)
	{
		auto current = pq.top(); //Get the value on the tope of the queue
		current->setVisited(true);
		//If we found the goal
		if (current->getID() == finish->getID())
		{
			foundPath = true;
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
				continue;

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

		//Remove from the top of the queue
		pq.pop();
	}

	return path;
}
