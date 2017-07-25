#include "NodeManager.h"
#include "Setting.h"
#include <algorithm>



#define SCREENX SETAPP->screensizeX
#define SCREENY SETAPP->screensizeY
#define GRIDLENGTH SETAPP->grid


void NodeManager::createNodes()
{
	
	for (int x = 0; x < SCREENX; x += GRIDLENGTH)
	{
		for (int y = 0; y < SCREENY; y += GRIDLENGTH)
		{
			
			gameNodes[index(x,y)].posX = (float)x;

			gameNodes[index(x,y)].posY = (float)y;
			
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



	int edgeNum = 0;
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
				

					edges[edgeNum].p1 = &gameNodes[index(x, y)];

					edges[edgeNum].p2 = &gameNodes[index(x + offsetX, y + offsetY)];

					edges[edgeNum].distance = calcDistance(edges[edgeNum].p1, edges[edgeNum].p2);

					if (std::find(edges[edgeNum].p1->edgeList.begin(), edges[edgeNum].p1->edgeList.end(), edges) != edges[edgeNum].p1->edgeList.end())
					{
						edges[edgeNum].p1->edgeList.push_back(edges);

						edges[edgeNum].p2->edgeList.push_back(edges);
					}
						
					edgeNum++;


				}
			}
			
			


		}

	}
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
	float DistanceX = (node1->posX - node2->posX) * (node1->posX - node2->posX);

	float DistanceY = (node1->posY - node2->posY) * (node1->posY - node2->posY);

	float distance = DistanceX + DistanceY;

	return distance;
}

std::list<Node*> NodeManager::aStar(Node * Start, Node * End)
{
	std::list<Node*>closed;

	std::list<Node*>open;


	open.push_front(Start);

	for (int x = 0; x < SCREENX; x += GRIDLENGTH)
	{
		for (int y = 0; y < SCREENY; y += GRIDLENGTH)
		{

			gameNodes[index(x, y)].setgScore(INFINITY);

			gameNodes[index(x, y)].setHscore(INFINITY);

			gameNodes[index(x, y)].setfScore(INFINITY);
			
			gameNodes[index(x, y)].camefrom = nullptr;


		}

	}

	Start->setgScore(0);

	Start->setHscore(calcHeuristic(Start, End));

	Start->setfScore(Start->hScore + Start->gScore);
	
	Node * current = Start;

	while (!open.empty())
	{
		float start = Start->fScore;

		float min;

		Node* search = open.front();
		for (auto &var : open)
		{
			if (search->fScore > var->fScore)
			{
				search = var;
			}
			else if (search->fScore == var->fScore)
			{
				if (search->hScore > var->hScore)
				{
					search = var;
				}
				else if (search->hScore == var->hScore)
				{
					continue;

				}
			}
			
		}

		current = search;

		if (current == End)
		{
			//add in the reconstruct path function
		}
		
		open.remove(current);
		
		closed.push_front(current);
		
		
		for (int i = 0; i < current->edgeList.size; i++)
		{
			std::find(auto &var : closed , current->edgeList
		

			
			

		}
	}

	return std::list<Node*>();
}



