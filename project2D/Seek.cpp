#include "Seek.h"
#include "Player.h"
#include"NodeManager.h"
#include "Setting.h"

Seek::Seek(Object * myself)
{
	Myself = myself;
	bTypes = SEEK;
	behaviourWeight = 0;
}


Seek::~Seek()
{
}

Vector2 Seek::update(float deltaTime)
{
	NodeManager NM;


	float speed = 50.0f;

	Vector2 v1 = Myself->position;

	Vector2 v2 = SETAPP->enemy->position;
	Vector2 v3 = v2 - v1;

	v3.normalise();

	v3 = v3 * speed * behaviourWeight;

	return v3;
}
