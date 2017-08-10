#pragma once
#include "Behaviours.h"

class PathFollowing : public Behaviours
{
public:

	virtual Vector2 update(float deltaTime);

	PathFollowing(Object * Myself);


	~PathFollowing();
};

