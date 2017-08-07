#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "BSM.h"
#include "GameStateTypes.h"
#include "Node.h"
#include "List.h"
#include "Vector2.h"
#include "Behaviours.h"

class Object
{
public:

// member variables for different objects
	Vector2 position;

	Vector2 velcocity;

	//float wide;

	float width;

	BSM * BM;

	Object * target;

	std::list<Node*> path;

	std::vector<Behaviours*> behaviourList;
	Object();

	//virtual draws the paddles and ball objects
	virtual void Draw();
	
	//virtual update function for all children of the object class
	virtual void Update(float DT);

	virtual ~Object();

};
