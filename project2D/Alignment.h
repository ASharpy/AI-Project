#pragma once
#include "Behaviours.h"

class Alignment : Behaviours
{
public:

	
	virtual Vector2 update(float deltaTime);
	
	Alignment(Object * myself);


	Vector2 point;

	int neighbourCount = 0;

	~Alignment();
};
