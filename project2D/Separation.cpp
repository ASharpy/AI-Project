#include "Separation.h"
#include "Setting.h"



Separation::Separation(Object * myself)
{
	Myself = myself;

	behaviourWeight = 0;

	bTypes = SEPARATION;

}

Vector2 Separation::update(float deltaTime)
{
	float speed = 150.0f;
	int neighbourCount = 0;
	for (auto &var : SETAPP->players)
	{
		bool CircCheck = SETAPP->playerCircleCheck(Myself, var, (400 + 400)*0.9f);

		if (CircCheck == true)
		{
			if (Myself == var)
			{
				continue;
			}
			point.x = point.x + (var->position.x - Myself->position.x);
			point.y = point.y + (var->position.y - Myself->position.y);
			neighbourCount++;


		}
	}

	if (neighbourCount == 0)
	{
		return Vector2{ 0,0 };
	}

	point.x = point.x / neighbourCount;
	point.y = point.y / neighbourCount;

	point.x = point.x * -1;
	point.y = point.y * -1;

	point.normalise();

	neighbourCount = 0;
	point = point * speed * behaviourWeight;



	return point;



}


Separation::~Separation()
{
}
