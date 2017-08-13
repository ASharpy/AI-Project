#include "FleeState.h"
#include "Setting.h"


FleeState::FleeState(Setting *_app, BSM * _BM, Object* myself)
{
	Myself = myself;
}
void FleeState::update(float DT)
{

	float speed = 150.0f;

	Vector2 v1 = Myself->position;

	Vector2 v2 = SETAPP->enemy->position;
	Vector2 v3 = v1 - v2;

	v3.normalise();

	v3 = v3 * speed;

	Myself->velcocity = v3;

}


FleeState::~FleeState()
{
}
