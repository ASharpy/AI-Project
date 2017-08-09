#include "Player.h"
#include <iostream>
#include "BSM.h"


Player::Player(float PosX, float PosY)
{
	
	position = {PosX,PosY};

	width = 15;

	BM = new BSM();

	
	//int playerindex2 = NM.index((int)player2->position.x, (int)player2->position.y);
}


void Player::update(float deltaTime)
{
	tempvec.x = 0;
	tempvec.y = 0;
	int ActiveBehaverCount = 0;
	for (auto &var : behaviourList)
	{
		tempvec = var->update(deltaTime);



		if (tempvec > 0 || var->behaviourWeight > 0)
		{
			desiredVector = desiredVector + tempvec;
			ActiveBehaverCount++;
		}
	}
	if (ActiveBehaverCount > 0)
	{
		velcocity = desiredVector / ActiveBehaverCount;
	}
}

void Player::seek(float behaviourWeight)
{
	for (auto &var : behaviourList)
	{
		if (var->bTypes == SEEK)
		{
			var->behaviourWeight = behaviourWeight;
		}
		else
		{
			//var->behaviourWeight = 0;
		}
	}
}

void Player::flee()
{
}

Player::~Player()
{
	delete BM;
}



//
//void Player::setup(aie::Renderer2D * m_2dRenderer, aie::Texture * m_texture, aie::Texture * m_paddleTexture)
//{
//
//}
////getting a key press and changing the tank accordingly
//void Player::update(float DT , aie::Input * input)
//{
//
//}
//
//void Player::draw()
//{
//	



