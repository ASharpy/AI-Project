#include "SeekState.h"
#include "Setting.h"
#include "Behaviours.h"

void SeekState::update(float DT)
{
	for (auto &var : SETAPP->players)
	{
		var->behaviourList.back()->update(DT);
	}

	
}

SeekState::SeekState(Setting *_app, BSM * _BM)
{
}


SeekState::~SeekState()
{
}
