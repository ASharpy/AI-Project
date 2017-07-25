#pragma once
#include "GameState.h"


class Application2D;
#define SETAPP Setting::getInstance()

class Setting
{
public:
	Application2D *app;
	static Setting* getInstance();


	/*
	This is the main game loop that checks for user input to move the paddles and moves the ball each frame
	also checks the collision function each frame for collisions
	@param deltaTime bootstraps deltaTime
	@param SM a state manager
	no returns
	*/
	void update(float deltaTime, StateManager * SM);


	void render();

	const int screensizeY = 720;

	const int screensizeX = 1280;

	const int grid = 20;
	
	const int nodeCount = (screensizeX / grid) * (screensizeY / grid);
private:
	Setting();
	~Setting();

	aie::Font * font;

	/*
	AABB collision to see if two rectangles are colliding 
	returns true or false depending on whether two objects are colliding
	*/
	bool checkCollision(float x, float y, float oWidth, float oHeight, float xTwo, float yTwo, float oTwoWidth, float oTwoHeight);



};

