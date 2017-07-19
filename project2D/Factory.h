#pragma once
#include "Object.h"

class Factory
{
public:

	/*
	Creates a new ball type object
	@param PosX the X position of the ball
	@param PosY the Y position of the ball
	returns new ball 
	*/
	static Object* MakeBall(float PosX, float PosY);
	
	/*
	Creates a new paddle type object
	@param PosX the X position of the paddle
	@param PosY the Y position of the paddle
	returns new paddle
	*/
	static Object* MakePaddle(float PosX, float PosY);
	Factory();

	~Factory();
};

