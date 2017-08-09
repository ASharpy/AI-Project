#include "Cohesion.h"
#include "Setting.h"


Vector2 Cohesion::update(float deltaTime)
{
	for (auto &var : SETAPP->players)
	{
		if (SETAPP->playerCircleCheck(Myself, var, (20 + 20)*0.9f));
		{
			point = point + var->position;
			neighbourCount++;


		}
	}
	point.x = point.x / neighbourCount;
	point.y = point.y / neighbourCount;

	Vector2 v = { point.x - Myself->position.x, point.y - Myself->position.y };

	v.normalise();

	return v;
}


Cohesion::Cohesion(Object * myself)
{
	Myself = myself;
	behaviourWeight = 0;
	bTypes = COHESION;
}


Cohesion::~Cohesion()
{

	
}
