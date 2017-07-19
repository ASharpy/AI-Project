#pragma once
#include "State.h"

class LoadState : public State
{
public:
	LoadState(Application2D *_app, StateManager * SM);
	virtual ~LoadState();

	/*
	calls the updateLoadText and UpdateStateTimer which write text to the screen tick of the counter and check to see if the counter is over respectivly
	@param deltaTime bootstraps delta time
	no returns
	*/
	virtual void update(float deltaTime);
	
	/*
	draws the text to the screen
	no returns
	*/
	virtual void render();


private:

	//The text to display to the screen
	char * loadText;

	//Time between the text changing
	const float delayTime = 0.3f;
	
	/*
	updates the text this gives the loading the changing ... after it
	@param deltaTime bootstraps delta time
	no returns
	*/
	void updateLoadText(float deltaTime);
	
	/*
	defines how long its loading for based on a timer
	@param deltaTime bootstraps delta time
	no returns
	*/
	void updateStateTimer(float deltaTime);
	
	float switchStateTimer;
};

