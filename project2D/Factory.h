#pragma once
#include "Object.h"
#include "Player.h"
#include "Enemy.h"

class Factory
{
public:


	/*
	returns a new enemy
	@param posX position X of an object
	@param posY position Y of an object
	returns new object
	*/
	static Object* MakeEnemy(float PosX, float PosY);
	Factory();

	~Factory();
};

