#include "PathFollowing.h"
#include "Player.h"
#include "Setting.h"



PathFollowing::PathFollowing(Object * myself)
{
	Myself = myself;
	behaviourWeight = 0;
	bTypes = PATHING;

}


PathFollowing::~PathFollowing()
{
}


Vector2 PathFollowing::update(float deltaTime)
{



	float speed = 150.0f;



	if (((Player*)Myself)->path.size() > 0)
	{


		float distance = 20.0f;

		float xDist = ((Player*)Myself)->position.x - ((Player*)Myself)->path.back()->posX;
		float yDist = ((Player*)Myself)->position.y - ((Player*)Myself)->path.back()->posY;


		float x = xDist * xDist;
		float y = yDist * yDist;
		float xy = x + y;

		if (xy < distance * distance)
		{
			((Player*)Myself)->path.pop_back();
		}




		if (((Player*)Myself)->path.size() > 0)
		{


			Vector2 v1 = Myself->position;

			Vector2 v2 = { ((Player*)Myself)->path.back()->posX,((Player*)Myself)->path.back()->posY };

			Vector2 v3 = v2 - v1;

			v3.normalise();

			v3 = v3 * speed * behaviourWeight;

			return v3;
		}
	}
	else
	{
		return Vector2{ 0,0 };
	}
}