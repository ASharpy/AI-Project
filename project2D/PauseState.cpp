#include "PauseState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "GameStateTypes.h"
#include "Setting.h"
#include "SplashState.h"

using namespace StateManagement;
PauseState::PauseState(Application2D *_app, StateManager *_SM) : State(_app, _SM)
{
	font = new aie::Font("./font/consolas.ttf", 50);
	pauseText = "Paused";

}

void PauseState::update(float dt)
{
	

	if (app->input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		SM->popState();
		SM->pushState(GAME);
	}
}

void PauseState::render()
{
	SETAPP->app->Renderer->drawText(font, pauseText, 540, 360, 50);
	SETAPP->render();
}




PauseState::~PauseState()
{
	delete font;
}
