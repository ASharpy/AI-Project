#pragma once
#include "Vector2.h"
#include <vector>

class Object;
class Behaviours
{
public:
	Behaviours() {};

	Behaviours(Object* myself);
	~Behaviours();

	Object* Myself;

	

	float behaviourWeight;

	virtual void update(float deltaTime) = 0;


};

