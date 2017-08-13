#include "Cohesion.h"
#include "Setting.h"


Vector2 Cohesion::update(float deltaTime)
{
	float speed = 100.0f;
	int neighbourCount = 0;

	for (auto &var : SETAPP->players)
	{

		if (SETAPP->playerCircleCheck(Myself, var, (300 + 300)*0.9f))
		{
		if (Myself == var)
		{
			continue;
		}
		point.x = point.x + var->position.x;
		point.y = point.y + var->position.y;
		neighbourCount++;


		}
	}
	if (neighbourCount == 0)
	{
		Vector2 emptyvec;
		return emptyvec;
	}
	else
	{


		point.x = point.x / neighbourCount;
		point.y = point.y / neighbourCount;

		Vector2 v = { point.x - Myself->position.x, point.y - Myself->position.y };

		v.normalise();

		v = v *speed * behaviourWeight;
		return v;
	}

	Vector2 emptyvec;
	return emptyvec;
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
