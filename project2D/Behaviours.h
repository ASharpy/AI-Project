#pragma once
#include "Vector2.h"
#include <vector>

//enum BehaviourEnum { SEEK, FLEE };

class Object;
class Behaviours
{
public:

	//BehaviourEnum behaviourType;

	Behaviours() {};

	Behaviours(Object* myself);
	~Behaviours();

	Object* Myself;

	

	float behaviourWeight;

	virtual void update(float deltaTime) = 0;


};

