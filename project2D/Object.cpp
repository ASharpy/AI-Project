#include "Object.h"
#include "Setting.h"
#include "Application2D.h"



Object::Object()
{
}

float Object::playerDistance(Vector2 player2)
{
	if (position.x > player2.x && position.y > player2.y)
	{
		xDist = position.x - player2.x;
		yDist = position.y - player2.y;
	}
	else
	{
		xDist = player2.x - position.x;
		yDist = player2.y - position.y;
	}

	return xDist + yDist;
}


void Object::Update(float DT)
{
}



Object::~Object()
{
}

void Object::Draw()
{
	SETAPP->app->Renderer->drawCircle(position.x, position.y, width);
}

