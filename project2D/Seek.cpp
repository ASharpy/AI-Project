#include "Seek.h"
#include "Player.h"


Seek::Seek(Object * myself)
{
	Myself = myself;
}


Seek::~Seek()
{
}

void Seek::update(float deltaTime)
{

	if (((Player*)Myself)->path.size() > 0)
	{


		float distance = 20.0f;

		float xDist = ((Player*)Myself)->position.x - ((Player*)Myself)->path.front()->posX;
		float yDist = ((Player*)Myself)->position.y - ((Player*)Myself)->path.front()->posY;


		float x = xDist * xDist;
		float y = yDist * yDist;
		float xy = x + y;

		if (xy < distance * distance)
		{
			((Player*)Myself)->path.pop_back();
		}
	

		

		if (((Player*)Myself)->path.size() > 0)
		{
			float speed = 1.0f;

			Vector2 v1 = Myself->position;

			Vector2 v2 = { ((Player*)Myself)->path.front()->posX,((Player*)Myself)->path.front()->posY };

			Vector2 v3 = v2 - v1;

			v3.normalise();

			Myself->velcocity = v3 * speed;
		}
	}
	else
	{
		Myself->velcocity = { 0,0 };
	}

}
