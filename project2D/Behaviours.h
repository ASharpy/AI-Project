#pragma once
#include "Vector2.h"
#include <vector>
#include "BehaviourStatetypes.h"


class Object;
class Behaviours
{
public:

	//enums of behaviour types for code readability 
	BehaviourTypes bTypes;

	//defualt constructor
	Behaviours() {};

	//constructor defining the objects which the behaviours effect
	Behaviours(Object* myself);

	~Behaviours();

	//object in which behaviours are effecting 
	Object* Myself;

	
	float behaviourWeight = 0;

	/*
	pure virtual update function for each behaviours
	@param deltaTime bootstraps delta time
	return vector2 of new velocity
	*/
	virtual Vector2 update(float deltaTime) = 0;


};

