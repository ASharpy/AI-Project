#include "SeekState.h"
#include "Setting.h"
#include "Behaviours.h"

void SeekState::update(float DT)
{
	
	float speed = 50.0f;

	Vector2 v1 = Myself->position;

	Vector2 v2 = SETAPP->enemy->position;
	Vector2 v3 = v2 - v1;

	v3.normalise();

	v3 = v3 * speed;
	Myself->velcocity = v3;

	
}

SeekState::SeekState(Setting *_app, BSM * _BM , Object* myself )
{
	Myself = myself;
}


SeekState::~SeekState()
{
}
