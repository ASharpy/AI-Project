#pragma once
#include "Behaviours.h"

class Seek : public Behaviours
{
public:

	
	Seek(Object * myself);

	~Seek();


	/*
	derived update function for seek that gets the enemies position and applies a force changing the player velecoity to the enemy direction
	@param DT bootstraps delta time
	return vector2 of new velocity
	*/
	virtual Vector2 update(float deltaTime);

};

