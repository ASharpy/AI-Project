#pragma once
#include "Behaviours.h"

class Seek : public Behaviours
{
public:


	Seek(Object * myself);

	~Seek();



	virtual Vector2 update(float deltaTime);

};

