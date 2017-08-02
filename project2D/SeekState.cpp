#include "SeekState.h"
#include "Setting.h"


void SeekState::update(float DT)
{
	SETAPP->player->posX += 100 * DT;
	SETAPP->player2->posX += 100 * DT;
}

SeekState::SeekState(Setting *_app, BSM * _BM)
{
}


SeekState::~SeekState()
{
}
