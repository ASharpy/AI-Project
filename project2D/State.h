#pragma once


class Application2D;
class StateManager;

namespace aie
{
	class Renderer2D;
	class Font;
}

class State
{
public:


	/*
	pure virtual update function that each state must have because the states dervive from state
	@param deltaTime bootstraps delta time
	no returns
	*/
	virtual void update(float deltaTime) = 0;
	
	/*
	pure virtual update function that each state must have because the states dervive from state
	@param deltaTime bootstraps delta time
	no returns
	*/
	virtual void render() = 0;

	/*
	pure virtual constructor that each state must have because the states dervive from state
	@param _app application2D
	@param _SM stateManager
	no returns
	*/
	State(Application2D *_app, StateManager * _SM) : app(_app), SM(_SM) {};
	virtual ~State() = default;

protected:

	aie::Font *font;
	Application2D *app;
	StateManager * SM;
};

