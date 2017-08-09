#include "Alignment.h"
#include "NodeManager.h"
#include "Setting.h"


Vector2 Alignment::update(float deltaTime)
{
	float speed = 100.0f;

	for (auto &var : SETAPP->players)
	{
		if (SETAPP->playerCircleCheck(Myself, var, (20 + 20)*0.9f));
		{
			point = point + var->velcocity;
			neighbourCount++;


		}
	}

	point.x = point.x / neighbourCount;
	point.y = point.y / neighbourCount;

	point.normalise();

	point = point * speed * behaviourWeight;

	return point;

	if (neighbourCount == 0)
	{
		return Vector2{ 0,0 };
	}
}

Alignment::Alignment(Object * myself)
{
	Myself = myself;
	behaviourWeight = 0;
	bTypes = ALIGNMENT;
}




Alignment::~Alignment()
{
}
