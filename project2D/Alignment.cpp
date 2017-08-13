#include "Alignment.h"
#include "NodeManager.h"
#include "Setting.h"


Vector2 Alignment::update(float deltaTime)
{
	float speed = 150.0f;
	int neighbourCount = 0;
	for (auto &var : SETAPP->players)
	{
		if (SETAPP->playerCircleCheck(Myself, var, (300 + 300)*0.9f))
		{
			if (Myself == var)
			{
				continue;
			}
			point = point + var->velcocity;
			neighbourCount++;


		}
	}

	if (neighbourCount == 0)
	{
		return Vector2{ 0,0 };
	}

	point.x = point.x / neighbourCount;
	point.y = point.y / neighbourCount;

	point.normalise();

	point = point * speed * behaviourWeight;
	


	return point;
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
