#include "Enemy.h"



Enemy::Enemy(float PosX, float PosY)
{
	position.x = PosX;

	position.y = PosY;

	width = 15;
	velcocity = { 0,0 };
}


Enemy::~Enemy()
{
}
