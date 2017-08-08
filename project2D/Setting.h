#pragma once
#include "GameState.h"
#include "Factory.h"
#include "NodeManager.h"

class Application2D;
#define SETAPP Setting::getInstance()
#define SCREENX SETAPP->screensizeX
#define SCREENY SETAPP->screensizeY
#define GRIDLENGTH SETAPP->grid
#define NODECOUNT SETAPP->nodeCount


class Setting
{
public:
	
	Application2D *app;
	static Setting* getInstance();

	void update(float deltaTime, StateManager * SM);

	int playerindex;

		int player2index;

	float timer = 1.0;

	void render();

	const int screensizeY = 720;

	const int screensizeX = 1280;

	const int grid = 20;

	NodeManager NM;

	const int nodeCount = (screensizeX / grid) * (screensizeY / grid);

	Object *player;

	Object * player2;

	Object * player3;

	Object * enemy;
private:
	Setting();
	~Setting();

	

	

	aie::Font * font;

	

	/*
	AABB collision to see if two rectangles are colliding 
	returns true or false depending on whether two objects are colliding
	*/
	bool checkCollision(float x, float y, float oWidth, float oHeight, float xTwo, float yTwo, float oTwoWidth, float oTwoHeight);

	//Object * player;

};

