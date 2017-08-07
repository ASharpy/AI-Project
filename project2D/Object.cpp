#include "Object.h"
#include "Setting.h"
#include "Application2D.h"



Object::Object()
{
}


void Object::Update(float DT)
{

}



Object::~Object()
{
}

void Object::Draw()
{
	SETAPP->app->Renderer->drawCircle(position.x, position.y, width);
}