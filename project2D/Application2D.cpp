#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameStateTypes.h"
#include "GameState.h"
#include "LoadState.h"
#include "MenuState.h"
#include "Setting.h"
#include "SplashState.h"
#include "PauseState.h"
#include "Exception.h"


using namespace StateManagement;
Application2D::Application2D()
{
	
}

Application2D::~Application2D()
{

}

bool Application2D::startup() {
	
	SETAPP->app = this;
	Renderer = new aie::Renderer2D();
	SM = new StateManager();
	input = aie::Input::getInstance();
	font = new aie::Font("./font/consolas.ttf", 10);
	SM->registerState(SPLASH, new SplashState(this, SM));
	SM->registerState(PAUSE, new PauseState(this, SM));
	SM->registerState(GAME, new GameState(this, SM));
	SM->registerState(LOADING, new LoadState(this, SM));
	SM->registerState(MENU, new MenuState(this, SM));
	SM->pushState(SPLASH);
	
	return true;
}

void Application2D::shutdown()
{
	delete SM;
	delete Renderer;
}




void Application2D::update(float deltaTime) {

	SM->updateState(deltaTime);
}



void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	Renderer->begin();

	SM->RenderState();


	Renderer->end();


}