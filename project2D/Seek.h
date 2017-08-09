#pragma once
#include "Behaviours.h"

class Seek : public Behaviours
{
public:


	Seek(Object * myself);

	~Seek();



	virtual void update(float deltaTime);

};

