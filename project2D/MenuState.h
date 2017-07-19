#pragma once
#include "State.h"
#include <Font.h>
#include <memory>
#include <Input.h>

namespace aie {

	class Font;
	class Renderer2D;
}

class MenuState : public State
{
public:

	MenuState::MenuState(Application2D *_app, StateManager *_SM);

	/*
	checks each frame for input and acts accordingly
	@param dt bootstraps delta time
	no returns
	*/
	virtual void update(float dt);

	/*
	draws the text on the screen and gives it the colour
	no returns
	*/
	virtual void render();

	virtual ~MenuState();


private:

	aie::Font * font;

	int WhatsSelected;

	int maxMenuOption;
};

