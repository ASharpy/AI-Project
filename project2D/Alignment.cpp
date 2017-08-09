#include "Alignment.h"
#include "NodeManager.h"
#include "Setting.h"


void Alignment::update(float deltaTime)
{
}

Alignment::Alignment(Object * myself)
{
	Myself = myself;
}

Vector2 Alignment::calcAlign(Object * enemy)
{

	for (auto &var : SETAPP->players )
	{
		if (SETAPP->playerCircleCheck(var, var++, (20 + 20)*0.9f));
			{
				point = point + var->velcocity;
				neighbourCount++;


			}
	}
	
	point.x = point.x / neighbourCount;
	point.y = point.y / neighbourCount;

	point.normalise();

	return point;

	if (neighbourCount == 0)
	{
		return Vector2();
	}
}


Alignment::~Alignment()
{
}
