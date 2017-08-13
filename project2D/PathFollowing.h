#pragma once
#include "Behaviours.h"

class PathFollowing : public Behaviours
{
public:

	/*
	derived update function for pathfollowing seeks to the next node in the a* path then removes it keeps going until there is no more nodes in the path
	@param DT bootstraps delta time
	return vector2 of new velocity
	*/
	virtual Vector2 update(float deltaTime);

	PathFollowing(Object * Myself);


	~PathFollowing();
};

