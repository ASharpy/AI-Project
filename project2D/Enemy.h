#pragma once
#include "Object.h"
class Enemy : public Object
{

public:

	//Virtual enemy constructor 
	//@param posX the position X of the object being created 
	//@param posY the position Y of the object being created 
	Enemy(float PosX, float PosY);


	virtual ~Enemy();
};

