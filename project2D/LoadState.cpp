#include "LoadState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "GameStateTypes.h"
#include "Setting.h"
#include "SplashState.h"


using namespace StateManagement;

LoadState::LoadState(Application2D *_app, StateManager *_SM) : State(_app, _SM)
{
	font = new aie::Font("./font/consolas.ttf", 50);
	loadText = "Loading";
	switchStateTimer = 0.0f;
}


LoadState::~LoadState()
{
	delete font;
}

void LoadState::update(float deltaTime)
{

	updateLoadText(deltaTime);
	updateStateTimer(deltaTime);
}

void LoadState::render()
{
	SETAPP->app->Renderer->drawText(font, loadText,540 ,360, 50);
}

void LoadState::updateLoadText(float deltaTime)
{
	static float updateClock;
	static int checkNum;
	updateClock += deltaTime;

	
	
	if (updateClock < delayTime) return;

	switch (checkNum) {
	case 0:
		loadText = "Loading";
		break;
	case 1:
		loadText = "Loading .";
		break;
	case 2:
		loadText = "Loading . .";
		break;
	case 3:
		loadText = "Loading . . .";
		checkNum = -1;
		break;
	default:
		exceptTHROW("checkNum is either too high or too low");
	}

	checkNum++;
	updateClock = 0;
}

void LoadState::updateStateTimer(float deltaTime)
{
	switchStateTimer += deltaTime;

	if (switchStateTimer < 3)
	{
		return;
	}

	app->getStateManager()->popState();
	app->getStateManager()->pushState(GAME);
}
