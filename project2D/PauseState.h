#pragma once
#include  "State.h"
class PauseState : public State
{
public:

	/*
	checks each frame to see if P is being press and if is then pop the pause state and push the game state
	@param dt bootstraps delta time
	no returns
	*/
	virtual void update(float dt);

	/*
	calls the game state render function to keep the shapes on the screen whilst the pause state is up
	no returns
	*/
	virtual void render();

	PauseState(Application2D *_app, StateManager *_SM);

	virtual ~PauseState();

private:
	char * pauseText;
};

