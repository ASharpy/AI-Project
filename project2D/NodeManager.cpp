#include "NodeManager.h"
#include "Setting.h"
#include <algorithm>





void NodeManager::createNodes()
{
	int i = 0;
	for (int x = 0; x < 1280; x += 20)
	{
		for (int y = 0; y < 720; y += 20)
		{

			gameNodes[i].posX = (float)x;
			gameNodes[i].posY = (float)y;

			for (int i = 5; i < 800 ; i += 36)
			{
				gameNodes[i].iswalkable = false;
			}
			
			for (int i = 843; i < 851; i++)
			{
				gameNodes[i].iswalkable = false;
			}
			
			gameNodes[i].index = i;

			i++;
			TOTAL_NODES = i;
		}
	}
	
	
}

int NodeManager::index(int posX, int posY)
{
	posX = posX / 20;
	posY = posY / 20;

	int i = posX * (720 / 20) + posY;

	return i;

}

NodeManager::NodeManager()
{
	gameNodes = new Node[2304];

		edges = new Edge[2304 * 8];
	
}


NodeManager::~NodeManager()
{
	delete[] gameNodes;

	delete[] edges;
}


void NodeManager::getEdges()
{
	Edge* edge;
	for (int i = 0; i < TOTAL_NODES; i++)
	{
		for (int j = i+1; j < TOTAL_NODES; j++)
		{
			if (CircleCheck(&gameNodes[i], &gameNodes[j], (20 + 20)*0.9f))
			{
				edges[TOTAL_EDGE].p1 = &gameNodes[i];

				edges[TOTAL_EDGE].p2 = &gameNodes[j];

				edges[TOTAL_EDGE].distance = calcDistance(&gameNodes[i], &gameNodes[j]);

				edge = &edges[TOTAL_EDGE];

				gameNodes[i].edgelist.push_back(edge);

				gameNodes[j].edgelist.push_back(edge);

				TOTAL_EDGE++;
			}
		}
	}

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


std::list<Node*> NodeManager::aStar(Node * Start, Node * End)
{
	std::list<Node*>closed;

	std::list<Node*>open;

	

	float tenative_gscore;



	open.push_front(Start);

	for (int i = 0; i < TOTAL_NODES; i++)
	{

		gameNodes[i].setgScore(INFINITY);

		gameNodes[i].setHscore(INFINITY);

		gameNodes[i].setfScore(INFINITY);

		gameNodes[i].camefrom = nullptr;
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

		if (std::find(closed.begin(), closed.end(), End) != closed.end())
		{
			return reconstructPath(End);
		}

		
		 //pops them from the open list to the closed list.
		open.remove(current);
		closed.push_front(current);



		

		for (auto &var : current->edgelist)
		{


			if (var->p2->iswalkable == false)
			{
				continue;
			}
			if (std::find(closed.begin(), closed.end(), var->p2) != closed.end())
			{
				continue;
			}
			//if its not in the open set already, chuck it in for comparision(ie, new nodes are being added to the open set with each iteration.)
			else if (std::find(open.begin(), open.end(), var->p2) == open.end())
			{
				open.push_front(var->p2);
				var->p2->camefrom = current;

			}


			tenative_gscore = current->gScore + calcDistance(current, var->p2);
			if (tenative_gscore >= var->p2->gScore)
			{
				continue;
			}

			var->p2->camefrom = current;
			var->p2->setgScore(tenative_gscore);
			var->p2->setfScore(var->p2->camefrom->gScore + calcHeuristic(var->p2, End));

		}
		
	}
	}


	std::list<Node*> NodeManager::reconstructPath(Node * current)
	{
	
		std::list<Node*> totalPath;

		totalPath.push_back(current);
		while (current->camefrom != nullptr)
		{
			current = current->camefrom;
			totalPath.push_back(current);
		}

		return totalPath;
	
	}

void NodeManager::findNeighbours(Node * node)
{
	
}



