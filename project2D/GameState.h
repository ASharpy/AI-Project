#pragma once
#include "State.h"

#include <Font.h>
#include "Object.h"
#include <Input.h>

namespace aie
{
	class Font;
	class Renderer2D;
}

class GameState : public State
{
public:


	/*
	call the setting classes update function which runs the game
	@param deltaTime bootstraps delta time
	no returns
	*/
	virtual void update(float deltaTime);
	
	/*
	call the setting classes render which draws the paddle and ball
	no returns
	*/
	virtual void render();

	GameState(Application2D *_app, StateManager * _SM);
	virtual ~GameState();

private:
};

