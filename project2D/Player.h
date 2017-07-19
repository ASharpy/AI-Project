#pragma once
#include "Object.h"
#include "Input.h"
class Player : public Object
{
public:
	Player();
	~Player();

	/*
	Sets up the texture and renderer "values" for the tank and its children
	@ param m_2dRenderer, the bootstrap renderer , m_tankBase, the PNG for the rectangle on the tank, m_texture, the PNG for the tank ,   m_tankTurret , the PNG for the turret of the tank
	no returns
	*/
	void setup(aie::Renderer2D* m_2dRenderer, aie::Texture* m_texture, aie::Texture* m_paddleTexture);

	Object paddle;

	/*
	updates each part of the tanks position, scale and rotation
	@ param DT the timer , input , AIE's key input 
	*/
	void update(float DT, aie::Input * input);

	/*
	draws each part of the tank
	no returns
	*/
	void draw();
};