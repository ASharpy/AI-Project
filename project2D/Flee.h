#pragma once
#include "Behaviours.h"

class Flee : public Behaviours
{
public:

	Flee(Object * myself);

	~Flee();

	virtual void update(float deltaTime);
};

