#pragma once
#include "BehaviourState.h"
#include "BSM.h"

class Setting;

class SeekState : public BehaviourState
{
public:

	void update(float DT);
	SeekState(Setting *_app, BSM * _BM);

	~SeekState();
};

