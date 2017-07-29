#include "Setting.h"
#include "Application2D.h"
#include "StateManager.h"
#include "GameStateTypes.h"
#include <string>
#include "Factory.h"
#include "Node.h"
#include "NodeManager.h"

Setting::Setting()
{

}


Setting * Setting::getInstance()
{
	static Setting setting;

	return &setting;
}

void Setting::update(float deltaTime, StateManager * SM)
{
	

}

void Setting::render()
{
	Node node;

	NodeManager NM;

	std::list<Node*> PATH;

	NM.createNodes();
	NM.getEdges();
	//PATH = NM.aStar(&NM.gameNodes[0], &NM.gameNodes[5]);
	NM.findNeighbours(&NM.gameNodes[0]);
	//NM.calcHeuristic(&NM.gameNodes[1], &NM.gameNodes[5]);
	int colour = 0;
	for (int i = 0; i < NM.TOTAL_NODES; i++)
	{

		SETAPP->app->Renderer->drawCircle(NM.gameNodes[i].posX, NM.gameNodes[i].posY, 2);
	}

	for (int i = 0; i <NM.TOTAL_EDGE; i++)
	{
		


			SETAPP->app->Renderer->drawLine(NM.edges[i].p1->posX, NM.edges[i].p1->posY, NM.edges[i].p2->posX, NM.edges[i].p2->posY);

		
	}
}
Setting::~Setting()
{

}


bool Setting::checkCollision(float x, float y, float oWidth, float oHeight, float xTwo, float yTwo, float oTwoWidth, float oTwoHeight)
{

	float x1Min = x - oWidth / 2;
	float x1Max = x + oWidth / 2;
	float y1Max = y + oHeight / 2;
	float y1Min = y = oHeight / 2;

	// AABB 2
	float x2Min = xTwo - oTwoWidth / 2;
	float x2Max = xTwo + oTwoWidth / 2;
	float y2Max = yTwo + oTwoHeight / 2;
	float y2Min = yTwo = oTwoHeight / 2;

	// Collision tests
	if (x1Max< x2Min || x1Min > x2Max) return false;
	if (y1Max< y2Min || y1Min > y2Max) return false;

	return true;

}

