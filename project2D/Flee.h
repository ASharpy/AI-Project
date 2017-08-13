#pragma once
#include "Behaviours.h"

class Flee : public Behaviours
{
public:

	Flee(Object * myself);

	~Flee();

	/*
	derived update function for flee that gets the enemies position and applies a force changing the player velecoity to the enemy direction
	@param DT bootstraps delta time
	return vector2 of new velocity
	*/
	virtual Vector2 update(float deltaTime);
};

