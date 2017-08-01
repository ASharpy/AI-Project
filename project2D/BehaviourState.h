#pragma once

class BSM;
class Application2D;

class BehaviourState
{
public:

	virtual void update(float dt) = 0;

	BehaviourState(Application2D * _app, BSM * _BM) : app(_app), BM(_BM) {};


	~BehaviourState() {};

protected:
	Application2D * app;

	BSM * BM;
	
};

