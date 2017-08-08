#include "Setting.h"
#include "Application2D.h"
#include "StateManager.h"
#include "GameStateTypes.h"
#include <string>
#include "Node.h"
#include "BehaviourStatetypes.h"
#include "SeekState.h"
#include "Behaviours.h"
#include "Seek.h"

Setting::Setting()
{
	NM.createNodes();
	NM.getEdges();
	player = Factory::Makeplayer(20, 20);
	player2 = Factory::Makeplayer(300, 300);
	player3 = Factory::Makeplayer(400, 400);
	enemy = Factory::MakeEnemy(30, 30);


	player2->BM->registerBState(SEEK, new SeekState(this, player2->BM));
	player->BM->registerBState(SEEK, new SeekState(this, player->BM));
	
	player2->BM->pushBehaveState(SEEK);
	player->BM->pushBehaveState(SEEK);

	player->behaviourList.push_back(new Seek(player));
	player2->behaviourList.push_back(new Seek(player2));

	playerindex = NM.index((int)player->position.x, (int)player->position.y);
	player2index = NM.index((int)player2->position.x, (int)player2->position.y);

}


Setting * Setting::getInstance()
{
	static Setting setting;

	return &setting;
}

void Setting::update(float deltaTime, StateManager * SM)
{


	
	//std::cout << dist << std::endl;

	
	timer = timer - deltaTime;

	player->position = (player->velcocity * deltaTime) + player->position;
	player2->position = (player2->velcocity * deltaTime) + player2->position;




	if (timer <= 0)
	{


		playerindex = NM.index((int)player->position.x, (int)player->position.y);

		player2index = NM.index((int)player2->position.x, (int)player2->position.y);

		player->path = NM.aStar(&NM.gameNodes[playerindex], &NM.gameNodes[player2index]);

		player->path.pop_back();
		player2->path = NM.aStar(&NM.gameNodes[player2index], &NM.gameNodes[500]);
		timer = 1.0;
		
		
	/*	if (dist < 1000)
		{
		system("pause");
		}*/
	}
	


	player2->BM->updateBehaveState(deltaTime);
	player->BM->updateBehaveState(deltaTime);
	
}

void Setting::render()
{
	

	//	foo = false;
	
	/*std::list<Node*> PATH;


	bool path = false;*/


	//PATH = NM.aStar(&NM.gameNodes[37], &NM.gameNodes[1000]);

	//Node * node = &NM.gameNodes[37];

	//for (int i = 0; i < NM.TOTAL_EDGE; i++)
	//{
	//	int edgeNum = 0;

	//	{
	//		SETAPP->app->Renderer->drawLine(NM.edges[i].p1->posX, NM.edges[i].p1->posY, NM.edges[i].p2->posX, NM.edges[i].p2->posY);

	//	}
	//}
	if (player->path.size() > 0)
	{


		Node* tempPtr = player->path.front();
		for (auto &var : player->path)
		{
			if (var == player->path.front())
			{
				continue;
			}

			SETAPP->app->Renderer->drawLine(tempPtr->posX, tempPtr->posY, var->posX, var->posY);
			tempPtr = var;
		}
	}

	//NM.findNeighbours(&NM.gameNodes[0]);
	//NM.calcHeuristic(&NM.gameNodes[1], &NM.gameNodes[5]);


	//int colour = 0;
	for (int i = 0; i < NM.TOTAL_NODES; i++)
	{


		if (NM.gameNodes[i].iswalkable == false)
		{
			continue;
		}
		SETAPP->app->Renderer->drawCircle(NM.gameNodes[i].posX, NM.gameNodes[i].posY, 2);


	}




	player2->Draw();
	player->Draw();
	player3->Draw();

	SETAPP->app->Renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	enemy->Draw();

	

}
Setting::~Setting()
{
	delete player;
	delete player2;
	delete player3;
	delete enemy;
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

