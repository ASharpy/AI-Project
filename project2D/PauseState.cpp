#include "PauseState.h"
#include <Renderer2D.h>
#include <Font.h>
#include "Application2D.h"
#include "GameStateTypes.h"
#include "Setting.h"
#include "SplashState.h"
#include "NodeManager.h"

using namespace StateManagement;
PauseState::PauseState(Application2D *_app, StateManager *_SM) : State(_app, _SM)
{
	
	pauseText = "Paused";

}

void PauseState::update(float dt)
{
	

	if (app->input->wasKeyPressed(aie::INPUT_KEY_P))
	{
		SM->popState();
		SM->pushState(PAUSE);
	}
}

void PauseState::render()
{
	NodeManager NM;

	for (int i = 0; i < NM.TOTAL_NODES; i++)
	{
		sprintf(str, "%d", NM.gameNodes[i].index);

		SETAPP->app->Renderer->drawText(SETAPP->app->font, str, NM.gameNodes[i].posX, NM.gameNodes[i].posY);
	}
	SETAPP->render();
}
	
	
	//SETAPP->app->Renderer->drawText(font, pauseText, 540, 360, 50);
	





PauseState::~PauseState()
{
	delete font;
}
