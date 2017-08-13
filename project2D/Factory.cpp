#include "Factory.h"


Object * Factory::MakeEnemy(float PosX, float PosY)
{
	return new Enemy(PosX,PosY);
}

Factory::Factory()
{
}


Factory::~Factory()
{
}


