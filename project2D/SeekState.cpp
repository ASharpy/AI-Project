#include "SeekState.h"
#include "Setting.h"


void SeekState::update(float DT)
{
	SETAPP->player->posX += 10 * DT;
}

SeekState::SeekState(Setting *_app, BSM * _BM)
{
}


SeekState::~SeekState()
{
}
