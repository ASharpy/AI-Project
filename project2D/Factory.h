#pragma once
#include "Object.h"
#include "Player.h"
#include "Enemy.h"

class Factory
{
public:

	/*
	Creates a new ball type object
	@param PosX the X position of the ball
	@param PosY the Y position of the ball
	returns new ball 
	*/
	static Object* Makeplayer(float PosX, float PosY);
	
	/*
	Creates a new paddle type object
	@param PosX the X position of the paddle
	@param PosY the Y position of the paddle
	returns new paddle
	*/
	static Object* MakeEnemy(float PosX, float PosY);
	Factory();

	~Factory();
};

