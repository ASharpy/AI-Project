#pragma once
#include <Application.h>
#include "Renderer2D.h"
#include "Player.h"
#include "StateManager.h"

class Application2D : public aie::Application {
public:


	Application2D();
	virtual ~Application2D();

	/*
	creates and registers all the objects and states
	returns true
	*/
	virtual bool startup();

	/*
	deletes the objects and states to stop memory leaks
	no returns
	*/
	virtual void shutdown();


	/*
	calls the update function for the active state
	no returns 
	*/
	virtual void update(float deltaTime);


	/*
	starts the game loop and checks whether it needs to end or not and calls the render function for the active states 
	no returns
	*/
	virtual void draw();
	aie::Input* input;
	StateManager *getStateManager() { return SM; };
	aie::Renderer2D *Renderer;

protected:

	StateManager *SM;

};