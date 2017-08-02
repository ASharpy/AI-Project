#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "BSM.h"
#include "GameStateTypes.h"
#include "Node.h"
#include "List.h"

class Object
{
public:

// member variables for different objects
	float posX;

	float posY;

	//float wide;

	float width;

	float Yvelocity;

	float Xvelocity;

	BSM * BM;

	Object * target;

	std::list<Node*> path;

	Object();

	//virtual draws the paddles and ball objects
	virtual void Draw();
	
	//virtual update function for all children of the object class
	virtual void Update(float DT);

	virtual void render();
	virtual ~Object();

};
