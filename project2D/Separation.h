#pragma once
#include "Behaviours.h"

class Separation : public Behaviours
{
public:

	Separation(Object *myself);

	Vector2 point;

	int neighbourCount = 0;

	Vector2 update(float deltaTime);

	~Separation();
};

