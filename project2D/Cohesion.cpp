#include "Cohesion.h"
#include "Setting.h"


Vector2 Cohesion::update(float deltaTime)
{
	float speed = 100.0f;

	for (auto &var : SETAPP->players)
	{
		
		if (SETAPP->playerCircleCheck(Myself, var, (300 + 300)*0.9f))
		{
			if (Myself == var)
			{
				continue;
			}
			point = point + var->position;
			neighbourCount++;


		}
	}
	if (neighbourCount == 0)
	{
		return Vector2{ 0,0 };
	}

	point.x = point.x / neighbourCount;
	point.y = point.y / neighbourCount;

	Vector2 v = { point.x - Myself->position.x, point.y - Myself->position.y };

	v.normalise();

	return v * speed * behaviourWeight;
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
