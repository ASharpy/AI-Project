#include "SeekState.h"
#include "Setting.h"
#include "Behaviours.h"

void SeekState::update(float DT)
{
	SETAPP->player->behaviourList.back()->update(DT);
	SETAPP->player2->behaviourList.back()->update(DT);
}

SeekState::SeekState(Setting *_app, BSM * _BM)
{
}


SeekState::~SeekState()
{
}
