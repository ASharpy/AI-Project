#pragma once
#include "Object.h"
#include "Input.h"
#include "Vector2.h"
#include "NodeManager.h"
#include "Node.h"

class Player : public Object
{
public:
	//Virtual player constructor 
	//@param posX the position X of the object being created 
	//@param posY the position Y of the object being created 
	Player(float PosX, float PosY);
	~Player();

	NodeManager * NM = new NodeManager;

	/*
	changes the behaviour weight of the seek behaviour
	@param behaviour weight defines what behaviours is used when
	no returns
	*/
	void seek(float behaviourWeight);

	/*
	changes the behaviour weight of the flee behaviour
	@param behaviour weight defines what behaviours is used when
	no returns
	*/
	void flee(float behaviourWeight);

	/*
	changes the behaviour weight of the cohesion behaviour
	@param behaviour weight defines what behaviours is used when
	no returns
	*/
	void Cohesion(float behaviourWeight);

	/*
	changes the behaviour weight of the alignment behaviour
	@param behaviour weight defines what behaviours is used when
	no returns
	*/
	void Alignment(float behaviourWeight);

	/*
	changes the behaviour weight of the separation behaviour
	@param behaviour weight defines what behaviours is used when
	no returns
	*/
	void Separation(float behaviourWeight);

	/*
	changes the behaviour weight of the pathfinding behaviour
	@param behaviour weight defines what behaviours is used when
	no returns
	*/
	void PathFinding(float behaviourWeight);

	// the timer for when to find a new a* path
	float timer = 1.0f;

	// what node the player is nearest
	int index;

	/*
	derived update function that calculates player velocity based on active behaviours and the velocities that the active behaviours return 
	@param behaviour bootstrap deltatime
	no returns
	*/
	void update(float deltaTime);


	Vector2 tempvec;

	Vector2 desiredVector;


	float minSpeed = 0.0f;
	
	float maxSpeed = 500.0f; 



};