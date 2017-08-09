#pragma once
#include "Behaviours.h"

class Alignment : Behaviours
{
public:

	
	virtual void update(float deltaTime);
	
	Alignment(Object * myself);

	Vector2 calcAlign(Object * enemy);

	Vector2 point;

	int neighbourCount = 0;

	~Alignment();
};

