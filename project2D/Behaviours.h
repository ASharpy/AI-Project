#pragma once
#include "Vector2.h"
#include <vector>
#include "BehaviourStatetypes.h"

//enum BehaviourEnum { SEEK, FLEE };

class Object;
class Behaviours
{
public:

	BehaviourTypes bTypes;
	//BehaviourEnum behaviourType;

	Behaviours() {};

	Behaviours(Object* myself);
	~Behaviours();

	Object* Myself;

	

	float behaviourWeight;

	virtual Vector2 update(float deltaTime) = 0;


};

