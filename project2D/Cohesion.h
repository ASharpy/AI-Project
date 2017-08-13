#pragma once
#include "Behaviours.h"

class Cohesion : public Behaviours
{
public:
	Cohesion(Object* Myself);

	~Cohesion();
	//temporary vector
	Vector2 point;

	/*
	derived update function for cohesion that gets the neighbours of players and steers them to their average positions
	@param DT bootstraps delta time
	return vector2 of new velocity
	*/
	virtual Vector2 update(float deltaTime);
};

