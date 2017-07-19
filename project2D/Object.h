#pragma once
#include "Application.h"
#include "Renderer2D.h"


class Object
{
public:

// member variables for different objects
	float posX;

	float posY;

	float wide;

	float tall;

	float Yvelocity;

	float Xvelocity;

	Object();

	//virtual draws the paddles and ball objects
	virtual void Draw();
	
	//virtual update function for all children of the object class
	virtual void Update(float DT);

	virtual ~Object();

};
