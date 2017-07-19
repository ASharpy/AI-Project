#include "NodeManager.h"
#include "Setting.h"

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
	NodeManager NM;

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

					edgeNum++;


				}
			}
			
			


		}

	}
}