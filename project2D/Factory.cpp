#include "Factory.h"





Object * Factory::Makeplayer(float PosX, float PosY)
{
	return new Player(PosX,PosY);
}

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


