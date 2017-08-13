#pragma once
#include "Behaviours.h"

class Alignment : public Behaviours
{
public:

	Alignment(Object* Myself);
	/*
	derived update function for alignment that gets the neighbours of players and steers them to their average headings
	@param DT bootstraps delta time
	return vector2 of new velocity
	*/
	virtual Vector2 update(float deltaTime);
	

	//Temporary vector
	Vector2 point;


	~Alignment();
};

