#include "NodeManager.h"
#include "Setting.h"
#include <algorithm>



#define SCREENX SETAPP->screensizeX
#define SCREENY SETAPP->screensizeY
#define GRIDLENGTH SETAPP->grid


void NodeManager::createNodes()
{
	int i = 0;
	for (int x = 0; x < SCREENX; x += GRIDLENGTH)
	{
		for (int y = 0; y < SCREENY; y += GRIDLENGTH)
		{

			gameNodes[i].posX = (float)x;
			gameNodes[i].posY = (float)y;

			gameNodes[i].index = i;

			i++;
			TOTAL_NODES = i;
		}
	}
	
	
}

int NodeManager::index(int posX, int posY)
{
	posX = posX / GRIDLENGTH;
	posY = posY / GRIDLENGTH;

	int i = posX * (SCREENY / GRIDLENGTH) + posY;

	return i;

}

NodeManager::NodeManager()
{
	gameNodes = new Node[SETAPP->nodeCount];

		edges = new Edge[SETAPP->nodeCount * 8];
	
}


NodeManager::~NodeManager()
{
	delete[] gameNodes;

	delete[] edges;
}


void NodeManager::getEdges()
{
	for (int i = 0; i < TOTAL_NODES; i++)
	{
		for (int j = i+1; j < TOTAL_NODES; j++)
		{
			if (CircleCheck(&gameNodes[i], &gameNodes[j], (GRIDLENGTH + GRIDLENGTH)*0.9f))
			{
				edges[TOTAL_EDGE].p1 = &gameNodes[i];

				edges[TOTAL_EDGE].p2 = &gameNodes[j];

				edges[TOTAL_EDGE].distance = calcDistance(&gameNodes[i], &gameNodes[j]);

				
				gameNodes[i].edgelist.push_front(edges[TOTAL_EDGE]);

				gameNodes[j].edgeslist[TOTAL_EDGE] = &edges[TOTAL_EDGE];

				TOTAL_EDGE++;
			}
		}
	}
	edgeslist[TOTAL_EDGE] = &edges[TOTAL_EDGE]edgeslist[TOTAL_EDGE] = &edges[TOTAL_EDGE]
	edgeslist[TOTAL_EDGE] = &edges[TOTAL_EDGE]
	/*
	for (int x = 0; x < SCREENX; x += GRIDLENGTH)
	{
		for (int y = 0; y < SCREENY; y += GRIDLENGTH)
		{
			

			for (int offsetX = -SETAPP->grid; offsetX <= GRIDLENGTH; offsetX = offsetX  + GRIDLENGTH)
			{
				for (int offsetY = -SETAPP->grid; offsetY <= GRIDLENGTH; offsetY += GRIDLENGTH)
				{
					if (x + offsetX < 0 || y + offsetY < 0 || x + offsetX >= SCREENX || y + offsetY >= SCREENY) continue;
					
					if (offsetX == 0 && offsetY == 0) continue;
				

				

				}
			}
			
			


		}

	}*/
}

float NodeManager::calcHeuristic(Node * node, Node * EndNode)
{
	float H; 

	float xDistance = abs(node->posX - EndNode->posX);

	float yDistance = abs(node->posY - EndNode->posY);

	if (xDistance < yDistance)
	{
		H = (GRIDLENGTH * 1.414 * yDistance) + (xDistance - yDistance);
	}
	else
	{
		H = (GRIDLENGTH * 1.414 * xDistance) + (yDistance - xDistance);
	}
	return H;
}

float NodeManager::calcDistance(Node* node1, Node* node2)
{
	float DistanceX = (node1->posX - node2->posX);// *(node1->posX - node2->posX);

	float DistanceY = (node1->posY - node2->posY);// *(node1->posY - node2->posY);

	float distance = (DistanceX*DistanceX) + (DistanceY*DistanceY);

	return distance;
}


bool NodeManager::CircleCheck(Node * node1, Node * node2, float Dist)
{
	float SqrDist = calcDistance(node1, node2);
	return SqrDist < (Dist * Dist);
}

//
//std::list<Node*> NodeManager::aStar(Node * Start, Node * End)
//{
//	std::list<Node*>closed;
//
//	std::list<Node*>open;
//
//	
//
//	float tenative_gscore;
//
////	std::list<Node*>::iterator iter;
//
//	open.push_front(Start);
//
//	for (int i = 0; i < TOTAL_NODES; i++)
//	{
//
//		gameNodes[i].setgScore(INFINITY);
//
//		gameNodes[i].setHscore(INFINITY);
//
//		gameNodes[i].setfScore(INFINITY);
//
//		gameNodes[i].camefrom = nullptr;
//	}
//
//	
//
//	Start->setgScore(0);
//
//	Start->setHscore(calcHeuristic(Start, End));
//
//	Start->setfScore(Start->hScore + Start->gScore);
//	
//	Node * current = Start;
//
//
//
//	while (!open.empty())
//	{
//		float start = Start->fScore;
//
//		float min;
//
//		Node* search = open.front();
//		//
//		for (auto &var : open)
//		{
//			if (search->fScore > var->fScore)
//			{
//				search = var;
//			}
//			else if (search->fScore == var->fScore)
//			{
//				if (search->hScore > var->hScore)
//				{
//					search = var;
//				}
//				else if (search->hScore == var->hScore)
//				{
//					continue;
//
//				}
//			}
//
//		}
//
//		current = search;
//
//		if (std::find(closed.begin(), closed.end(), End) != closed.end())
//		{
//			return reconstructPath(current);
//		}
//
//		
//		// pops them from the open list to the closed list.
//		open.remove(current);
//		closed.push_front(current);
//
//
//
//		
//
//		/*for (auto &var : current->edgeList)
//		{
//		*/	
//			
//			if (var->p2->iswalkable == false)
//			{
//				continue;
//			}
//			if (std::find(closed.begin(), closed.end(), var->p2) != closed.end())
//			{
//				continue;
//			}
//			// if its not in the open set already, chuck it in for comparision (ie, new nodes are being added to the open set with each iteration.)
//			else if (std::find(open.begin(), open.end(), var->p2) == open.end())
//			{
//				open.push_front(var->p2);
//				var->p2->camefrom = current;
//
//			}
//
//			//
//			tenative_gscore = current->gScore + calcDistance(current, var->p2);
//			if (tenative_gscore >= var->p2->gScore)
//			{
//				continue;
//			}
//
//			var->p2->camefrom = current;
//			var->p2->setgScore(tenative_gscore);
//			var->p2->setfScore(var->p2->camefrom->gScore + calcHeuristic(var->p2, End));
//
//
//		
//	}
//	}
//
//
//	std::list<Node*> NodeManager::reconstructPath(Node * current)
//	{
//	
//		std::list<Node*> totalPath;
//
//		totalPath.push_back(current);
//		while (current->camefrom != nullptr)
//		{
//			current = current->camefrom;
//			totalPath.push_back(current);
//		}
//
//		return totalPath;
//	
//	}
//
//void NodeManager::findNeighbours(Node * node)
//{
//	
//
//	/*for (std::vector<Edge*>::iterator iter = node->edgeList.begin(); iter != node->edgeList.end(); ++iter)
//	{
//	
//	}*/
//}
//
//

