#include "SplashState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "GameStateTypes.h"
#include "Setting.h"



using namespace StateManagement;

SplashState::SplashState(Application2D * _app, StateManager * SM) : State(_app, SM)
{
	font = new aie::Font("./font/consolas.ttf", 50);
	actionfont = new aie::Font("./font/consolas.ttf", 30);
	splashText = "Pong Game";
	actionText = "Press Space To Continue";
}

SplashState::~SplashState()
{
	delete font;
	delete actionfont;
}

void SplashState::update(float deltaTime)
{

	if (app->input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
	
			SM->popState();
			SM->pushState(MENU);
	
	}

}

void SplashState::render()
{

	SETAPP->app->Renderer->drawText(font, splashText, 540, 460, 50);
	SETAPP->app->Renderer->drawText(actionfont, actionText, 480, 380, 50);

}

