#pragma once
#include "State.h"

class SplashState : public State
{
public:
	SplashState(Application2D *_app, StateManager * SM);
	virtual ~SplashState();

	/*
	checks to see if space has been pressed then act accordinly 
	@param dt bootstraps delta time
	no returns
	*/
	virtual void update(float deltaTime);

	/*
	draws the text to the screen 
	no returns
	*/
	virtual void render();

private:

	aie::Font * actionfont;
	char * splashText;
	char * actionText;
};


