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
#include "FleeState.h"
#include <iostream>

Setting::Setting()
{
	NM.createNodes();
	NM.getEdges();

	players.push_back(new Player(400, 400));
	players.push_back(new Player(200,200));
	players.push_back(new Player(300, 300));

	fleePlayers.push_back(new Player(550, 550));
	fleePlayers.push_back(new Player(450, 450));

	pathPlayers.push_back(new Player(350, 350));
	pathPlayers.push_back(new Player(250, 250));

	FMLPlayers.push_back(new Player(350, 400));
	FMLPlayers.push_back(new Player(250, 400));


	enemy = Factory::MakeEnemy(50, 50);



	for (auto &var: players)
	{
		var->behaviourList.push_back(new Seek(var));
		var->behaviourList.push_back(new Separation(var));
		var->behaviourList.push_back(new Alignment(var));
		var->behaviourList.push_back(new Cohesion(var));
	}



	for (auto &var : fleePlayers)
	{
		var->behaviourList.push_back(new Flee(var));
	}

	for (auto &var : pathPlayers)
	{
		var->behaviourList.push_back(new PathFollowing(var));
	}



	for (auto &var : FMLPlayers)
	{

		var->BM->registerBState(SEEK, new SeekState(this, var->BM,var));
		var->BM->registerBState(FLEE, new FleeState (this, var->BM, var));
		

			var->BM->pushBehaveState(SEEK);
	}
}


Setting * Setting::getInstance()
{
	static Setting setting;

	return &setting;
}

void Setting::update(float deltaTime, StateManager * SM)
{



	for (auto &var : players)
	{


		var->Alignment(1.0f);
		var->Cohesion(0.0f);
		var->Separation(0.5f);
		var->seek(1.5f);

	}


	for (auto &var : pathPlayers)
	{
		
		var->timer -= deltaTime;
		var->PathFinding(1.0f);
		

		enemyindex = NM.index((int)enemy->position.x, (int)enemy->position.y);
		var->index = NM.index((int)var->position.x, (int)var->position.y);

		if (var->timer <= 0)
		{
			


				var->path = NM.aStar(&NM.gameNodes[var->index], &NM.gameNodes[enemyindex]);

				if (var->path.size() > 0)
				{
					var->path.pop_back();

				

				var->timer = 1.0;
				timer = 1.0;
			}
		}
		var->update(deltaTime);
		var->position = (var->velcocity * deltaTime) + var->position;
	}
	

	for (auto &var : players)
	{
		var->update(deltaTime);
		var->position = (var->velcocity * deltaTime) + var->position;
	}


	for (auto &var : fleePlayers)
	{
		enemyindex = NM.index((int)enemy->position.x, (int)enemy->position.y);
		var->index = NM.index((int)var->position.x, (int)var->position.y);

		dist = NM.calcDistance(&NM.gameNodes[enemyindex], &NM.gameNodes[var->index]);

		dist /= 20;

		if (dist < 1000)
		{
			var->flee(1.0f);
		}
		else
		{
			var->flee(0.0f);
		}
		
		var->update(deltaTime);
		var->position = (var->velcocity * deltaTime) + var->position;
	}



	for (auto &var : FMLPlayers)
	{
		enemyindex = NM.index((int)enemy->position.x, (int)enemy->position.y);
		var->index = NM.index((int)var->position.x, (int)var->position.y);

		dist = NM.calcDistance(&NM.gameNodes[enemyindex], &NM.gameNodes[var->index]);

		dist /= 20;
		if (dist < 1000)
		{
			var->BM->popBehaveState();
			var->BM->pushBehaveState(FLEE);
			var->BM->updateBehaveState(deltaTime);
			var->position = (var->velcocity * deltaTime) + var->position;

		}
		else
		{
			var->BM->popBehaveState();
			var->BM->pushBehaveState(SEEK);
			var->BM->updateBehaveState(deltaTime);
			var->position = (var->velcocity * deltaTime) + var->position;
		}
	


	}

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

		enemy->position = (enemy->velcocity * deltaTime) + enemy->position;

	}


void Setting::render()
{

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



	for (auto &var : fleePlayers)
	{
		SETAPP->app->Renderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);
		var->Draw();
	}



	for (auto &var : pathPlayers)
	{
		SETAPP->app->Renderer->setRenderColour(1.0f, 0.0f, 1.0f, 1.0f);
		var->Draw();
	}



	for (auto &var : FMLPlayers)
	{
		SETAPP->app->Renderer->setRenderColour(1.0f, 1.0f, 0.0f, 1.0f);
		var->Draw();
	}


	SETAPP->app->Renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	enemy->Draw();

	

}

bool Setting::playerCircleCheck(Object * player1, Player * player2, float dist)
{

	float DistanceX = (player1->position.x - player2->position.y);

	float DistanceY = (player1->position.y - player2->position.y);

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


