#include "MenuState.h"
#include <Renderer2D.h>
#include "StateManager.h"
#include "Application2D.h"
#include "GameStateTypes.h"
#include "Setting.h"
#include <iostream>

using namespace StateManagement;

MenuState::MenuState(Application2D * _app, StateManager * _SM) : State(_app, _SM)
{
	font = new aie::Font("./font/consolas.ttf", 32);
	WhatsSelected = 0;
	maxMenuOption = 1;

}

void MenuState::update(float dt)
{

		if (app->input->isKeyDown(aie::INPUT_KEY_DOWN))
		{
			WhatsSelected = 0;
		}

		else if (app->input->isKeyDown(aie::INPUT_KEY_UP))
		{
			
			WhatsSelected = 1;
				
		}

		if (app->input->isKeyDown(aie::INPUT_KEY_ENTER))
		{
			if (WhatsSelected == 1)
			{
				SM->popState();
				SM->pushState(GAME);
			};
			if (WhatsSelected == 0)
			{
				app->quit();
			}
		}
		

}



void MenuState::render()
{
	SETAPP->app->Renderer->setRenderColour(0.1f, 0.1f, 0.1f, 1.0f);
	SETAPP->app->Renderer->drawBox(590, 520, 300, 60);

	SETAPP->app->Renderer->setRenderColour(0.5f, 0.5f, 0.5f, 1.0f);
	SETAPP->app->Renderer->drawText(font, "AI", 500, 500);
	if (WhatsSelected == 0)
	{
		SETAPP->app->Renderer->setRenderColour(1.0f, 0.0f, 0.0f, 1.0f);

	}
	else
	{
		SETAPP->app->Renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	SETAPP->app->Renderer->drawText(font, "Start AI", 500, 400);

	if (WhatsSelected == 1)
	{
		

	}
	else
	{
		SETAPP->app->Renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
	}
	SETAPP->app->Renderer->drawText(font, "Quit", 500, 350);

}

MenuState::~MenuState()
{
	delete font;
}


