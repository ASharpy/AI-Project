#pragma once
#include "Object.h"
class Enemy : public Object
{

public:

	void seek();
	void flee();
	Enemy(float PosX, float PosY);

	virtual ~Enemy();
};

