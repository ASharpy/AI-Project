#pragma once

class BSM;
class Setting;

class BehaviourState
{
public:

	virtual void update(float dt) = 0;

	BehaviourState(Setting * _app, BSM * _BM) : app(_app), BM(_BM) {};

	BehaviourState() {};

	~BehaviourState() {};

protected:
	Setting * app;

	BSM * BM;
	
};

