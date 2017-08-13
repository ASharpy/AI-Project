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
#include "Flee.h"
#include "PathFollowing.h"
#include "Cohesion.h"
#include "Alignment.h"
#include "Separation.h"
#include <iostream>

Setting::Setting()
{
	NM.createNodes();
	NM.getEdges();
	players.push_back(new Player(300,300));
	players.push_back(new Player(200, 200));
	players.push_back(new Player(400, 400));
	players.push_back(new Player(500, 500));
	players.push_back(new Player(300, 300));
	enemy = Factory::MakeEnemy(50, 50);

	for (auto &var : players)
	{


		var->BM->registerBState(SEEK, new SeekState(this, var->BM));
		//player->BM->registerBState(SEEK, new SeekState(this, player->BM));

		var->BM->pushBehaveState(SEEK);
		//player->BM->pushBehaveState(SEEK);

		var->behaviourList.push_back(new Separation(var));
		var->behaviourList.push_back(new Alignment(var));
		var->behaviourList.push_back(new Cohesion(var));
		var->behaviourList.push_back(new Seek(var));

		//player2->behaviourList.push_back(new Flee(player2));
	}
	
}


Setting * Setting::getInstance()
{
	static Setting setting;

	return &setting;
}

void Setting::update(float deltaTime, StateManager * SM)
{
	Vector2 prevPos = enemy->position;
	//playerindex = NM.index((int)player->position.x, (int)player->position.y);

	//player2index = NM.index((int)player2->position.x, (int)player2->position.y);

	
	//std::cout << dist << std::endl;
	timer -= deltaTime;


	for (auto &var : players)
	{
		enemyindex = NM.index((int)enemy->position.x, (int)enemy->position.y);
		var->index = NM.index((int)var->position.x, (int)var->position.y);

		/*dist = NM.calcDistance(&NM.gameNodes[enemyindex], &NM.gameNodes[var->index]);
		dist /= 20;*/
	
		var->Alignment(1.0f);
		var->Cohesion(1.0f);
		var->Separation(1.0f);
		//var->seek(1.0f);
			
		

		
			//if (timer <= 0)
			//{
			//	var->path = NM.aStar(&NM.gameNodes[var->index], &NM.gameNodes[enemyindex]);

			//		if (var->path.size() > 0)
			//		{
			//			var->path.pop_back();

			//		}

			//		timer = 1.0;
			//	}
			

			var->update(deltaTime);
	}
	
	

	


	//float dist = NM.calcDistance(&NM.gameNodes[playerindex], &NM.gameNodes[enemyindex]);
	//dist = dist / 20;
	//std::cout << dist << std::endl;

	//if (dist < 8000)
	//{
	
		

	/*	if (var->position.x > 1280)
		{
			var->velcocity = 0;
		}
		else if (var->position.x < 0)
		{
			var->velcocity = 0;
		}
		else if (var->position.y < 0)
		{
			var->velcocity = 0;
		}
		else if (var->position.y > 720)
		{
			var->velcocity = 0;
		*///}
		
		
	//}


	//timer = timer - deltaTime;
	



	










		if (app->input->isKeyDown(aie::INPUT_KEY_A))
		{

			if (enemy->velcocity.x < -200)
			{
				enemy->velcocity.x = enemy->velcocity.x - 0;

			}
			else
			{
				enemy->velcocity.x = enemy->velcocity.x - 50;

			}
		}

		if (app->input->isKeyDown(aie::INPUT_KEY_D))
		{

			if (enemy->velcocity.x > 200)
			{
				enemy->velcocity.x = enemy->velcocity.x - 0;

			}
			else
			{
				enemy->velcocity.x = enemy->velcocity.x + 50;

			}
		}

		if (app->input->isKeyDown(aie::INPUT_KEY_W))
		{
			if (enemy->velcocity.y > 200)
			{
				enemy->velcocity.y = enemy->velcocity.y - 0;

			}
			else
			{
				enemy->velcocity.y = enemy->velcocity.y + 50;

			}
		}

		if (app->input->isKeyDown(aie::INPUT_KEY_S))
		{
			if (enemy->velcocity.y < -200)
			{
				enemy->velcocity.y = enemy->velcocity.y - 0;

			}
			else
			{
				enemy->velcocity.y = enemy->velcocity.y - 50;

			}
		}


		if (enemy->position.x > 1265)
		{
		
		}
		if (enemy->position.x < 0)
		{
			;
		}
		if (enemy->position.y < 0)
		{
		
		}
		if (enemy->position.y > 705)
		{
		
		}

		enemy->position = (enemy->velcocity * deltaTime) + enemy->position;

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
	//if (player->path.size() > 0)
	//{


	//	Node* tempPtr = player->path.front();
	//	for (auto &var : player->path)
	//	{
	//		if (var == player->path.front())
	//		{
	//			continue;
	//		}

	//		SETAPP->app->Renderer->drawLine(tempPtr->posX, tempPtr->posY, var->posX, var->posY);
	//		tempPtr = var;
	//	}
	//}

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



	for (auto &var : players)
	{


		var->Draw();
	}
	SETAPP->app->Renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	enemy->Draw();

	

}

bool Setting::playerCircleCheck(Object * player1, Player * player2, float dist)
{

	float DistanceX = (player1->position.x - player2->position.y);// *(node1->posX - node2->posX);

	float DistanceY = (player1->position.y - player2->position.y);// *(node1->posY - node2->posY);

	float distance = (DistanceX*DistanceX) + (DistanceY*DistanceY);
	
	float SqrDist = distance;

		return SqrDist < (dist * dist);
	
}

Setting::~Setting()
{
	for (auto &var : players)
	{
		delete var;
	}

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

