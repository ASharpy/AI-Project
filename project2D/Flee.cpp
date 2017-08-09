#include "Flee.h"
#include "Enemy.h"
#include "Setting.h"
#include "NodeManager.h"


Flee::Flee(Object * myself)
{
	Myself = myself;
	behaviourWeight = 1;
	bTypes = FLEE;
}


Flee::~Flee()
{
}

Vector2 Flee::update(float deltaTime)
{
	NodeManager NM;


	float speed = 100.0f;

	Vector2 v1 = Myself->position;

	Vector2 v2 = SETAPP->enemy->position;
	Vector2 v3 = v1 - v2;

	v3.normalise();

	v3 = v3 * speed * behaviourWeight;

	return v3;



}
