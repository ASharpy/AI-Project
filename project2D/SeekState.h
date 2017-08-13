#pragma once
#include "BehaviourState.h"
#include "BSM.h"

class Setting;

class SeekState : public BehaviourState
{
public:

	/*
	derived update function for seek that gets the enemies position and applies a force changing the player velecoity to the enemy direction
	@param DT bootstraps delta time
	no returns
	*/
	void update(float DT);

	SeekState(Setting *_app, BSM * _BM, Object* myself);


	~SeekState();
};

