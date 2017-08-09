#pragma once
#include "Behaviours.h"

class Cohesion : public Behaviours
{
public:
	Cohesion(Object* Myself);

	~Cohesion();

	Vector2 point;

	int neighbourCount = 0;
	
	virtual Vector2 update(float deltaTime);
};

