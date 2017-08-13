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

	//singleton
	static Setting* getInstance();

	void update(float deltaTime, StateManager * SM);

	// a list of players that are affected by seek, separation and alignment 
	std::vector<Player*> players;

	// a list of players that are affected by flee
	std::vector<Player*> fleePlayers;

	// a list of players that are affected by pathfinding
	std::vector<Player*> pathPlayers;

	// a list of players that use the state machine
	std::vector<Player*> FMLPlayers;

	//the node on which the enemy is nearest
	int enemyindex;

	float timer = 1.0;

	//calls the render function
	void render();

	float dist;
	const int screensizeY = 720;

	const int screensizeX = 1280;

	const int grid = 20;

	NodeManager NM;

	/*
	checks whether another player is within a certain radius of another
	@param player1 a player object 
	@param player2 a second player object
	@param dist the distance between players
	returns whether it found a player or not
	*/
	bool playerCircleCheck(Object* player1, Player* player2, float dist);

	const int nodeCount = (screensizeX / grid) * (screensizeY / grid);


	Object * enemy;

	Setting();

	~Setting();

private:


	

	

	aie::Font * font;

};

