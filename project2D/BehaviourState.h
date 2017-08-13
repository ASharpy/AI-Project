#pragma once
#include "Vector2.h"
#include "Object.h"

class BSM;
class Setting;

class BehaviourState
{
public:

	virtual void update(float dt) = 0;


	/*
	pure virtual constructor that each state must have because the states dervive from state
	@param _app application2D
	@param _BSM BSM
	@param _myself an object 
	no returns
	*/
	BehaviourState(Setting * _app, BSM * _BM , Object * myself) : app(_app), BM(_BM) { Myself = myself; };

	//Defualt Constructor 
	BehaviourState() {};

	Object *Myself;

	~BehaviourState() {};

protected:
	Setting * app;

	BSM * BM;
	
};

