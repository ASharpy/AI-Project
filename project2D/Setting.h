#pragma once
#include "GameState.h"
#include "Factory.h"
#include "NodeManager.h"

class Application2D;
#define SETAPP Setting::getInstance()


class Setting
{
public:
	Application2D *app;
	static Setting* getInstance();

	void update(float deltaTime, StateManager * SM);

	

	void render();

	const int screensizeY = 720;

	const int screensizeX = 1280;

	const int grid = 20;
	
	const int nodeCount = (screensizeX / grid) * (screensizeY / grid);
private:
	Setting();
	~Setting();

	

	NodeManager *NM;

	aie::Font * font;

	Object *player;

	/*
	AABB collision to see if two rectangles are colliding 
	returns true or false depending on whether two objects are colliding
	*/
	bool checkCollision(float x, float y, float oWidth, float oHeight, float xTwo, float yTwo, float oTwoWidth, float oTwoHeight);

	//Object * player;

};

