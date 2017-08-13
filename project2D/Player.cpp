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


		if (desiredVector.x != 0.0f && desiredVector.y != 0.0f)
		{
			
			desiredVector.x = desiredVector.x / ActiveBehaverCount;
			desiredVector.y = desiredVector.y / ActiveBehaverCount;
			
		}

		if (tempvec > 0 || var->behaviourWeight > 0)
		{
			desiredVector = desiredVector + tempvec;
			ActiveBehaverCount++;
			
		}
	}

	if (ActiveBehaverCount > 0)
	{
		velcocity = desiredVector;
		
	}

	if ((velcocity.magnitude() * velcocity.magnitude()) < (minSpeed*minSpeed))
	{
		if (velcocity.x != 0.0f || velcocity.y != 0.0)
		{
			velcocity.normalise();
			velcocity * minSpeed;
		}
	}
	else if ((velcocity.magnitude() * velcocity.magnitude()) > (maxSpeed*maxSpeed))
	{
		velcocity.normalise();
		velcocity * maxSpeed;
	}

	
	desiredVector = { 0.0f, 0.0f };
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

void Player::flee(float behaviourWeight)
{
	for (auto &var : behaviourList)
	{
		if (var->bTypes == FLEE)
		{
			var->behaviourWeight = behaviourWeight;
		}
		else
		{
			//var->behaviourWeight = 0;
		}
	}
}

void Player::Cohesion(float behaviourWeight)
{
	for (auto &var : behaviourList)
	{
		if (var->bTypes == COHESION)
		{
			var->behaviourWeight = behaviourWeight;
		}
		else
		{
			//var->behaviourWeight = 0;
		}
	}
}

void Player::Alignment(float behaviourWeight)
{
	for (auto &var : behaviourList)
	{
		if (var->bTypes == ALIGNMENT)
		{
			var->behaviourWeight = behaviourWeight;
		}
		else
		{
			//var->behaviourWeight = 0;
		}
	}
}

void Player::Separation(float behaviourWeight)
{
	for (auto &var : behaviourList)
	{
		if (var->bTypes == SEPARATION)
		{
			var->behaviourWeight = behaviourWeight;
		}
		else
		{
			//var->behaviourWeight = 0;
		}
	}
}

void Player::PathFinding(float behaviourWeight)
{
	for (auto &var : behaviourList)
	{
		if (var->bTypes == PATHING)
		{
			var->behaviourWeight = behaviourWeight;
		}
		else
		{
			//var->behaviourWeight = 0;
		}
	}
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



