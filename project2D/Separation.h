#pragma once
#include "Behaviours.h"

class Separation : public Behaviours
{
public:

	Separation(Object *myself);

	//temporary vectors
	Vector2 point;

	/*
	derived update function for separation that gets the neighbours of players and steers them away from their neighbours
	@param DT bootstraps delta time
	return vector2 of new velocity
	*/
	Vector2 update(float deltaTime);

	~Separation();
};

