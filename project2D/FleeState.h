#pragma once
#include "BehaviourState.h"
#include "BSM.h"

class Setting;

class FleeState : public BehaviourState
{
public:
	
	/*
	derived update function for flee that gets the enemies position and applies a force changing the player velecoity to the opposite direction
	@param DT bootstraps delta time
	no returns
	*/
	void update(float DT);


	FleeState(Setting *_app, BSM * _BM, Object* myself);

	~FleeState();
};

