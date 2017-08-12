#pragma once
#include "Object.h"
#include "Input.h"
#include "Vector2.h"
#include "NodeManager.h"
#include "Node.h"

class Player : public Object
{
public:
	Player(float PosX, float PosY);
	~Player();

	NodeManager * NM = new NodeManager;

	void seek(float behaviourWeight);
	void flee();

	int index;

	void update(float deltaTime);

	Vector2 tempvec;

	Vector2 desiredVector;


	float minSpeed = 10.0f;
	
	float maxSpeed = 100.0f; 

	int noBehaviour;
	
	//void setup(aie::Renderer2D* m_2dRenderer, aie::Texture* m_texture, aie::Texture* m_paddleTexture);

	//Object paddle;

	//
	//void update(float DT, aie::Input * input);

	//
	//void draw();
};