#include "Factory.h"





Object * Factory::Makeplayer(float PosX, float PosY)
{
	return new Player(PosX,PosY);
}

Object * Factory::MakeEnemy(float PosX, float PosY)
{
	return nullptr;
}

Factory::Factory()
{
}


Factory::~Factory()
{
}


