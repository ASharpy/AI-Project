#include "Player.h"
#include <iostream>


Player::Player()
{
}


Player::~Player()
{
}

void Player::setup(aie::Renderer2D * m_2dRenderer, aie::Texture * m_texture, aie::Texture * m_paddleTexture)
{
//creating an object and setting its parent
	Object::setup(m_2dRenderer, m_texture);;
	paddle.setup(m_2dRenderer, m_paddleTexture);
	paddle.position = Vector2(0, 0);
	paddle.origin.y = 0.0f;
}
//getting a key press and changing the tank accordingly
void Player::update(float DT , aie::Input * input)
{
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		position = position  + Vector2(-5, 0);
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		position = position + Vector2(5, 0);
	}

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		position = position + Vector2(0, 5);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		position = position + Vector2(0, -5);
	}
	if (input->isKeyDown(aie::INPUT_KEY_Q))
	{
	       rotation += 10.0f * DT;

	}
	if (input->isKeyDown(aie::INPUT_KEY_E))
	{
		rotation -= 10.0f * DT;

	}

	//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	//{
	//	tankbase.rotation += 10.0f* DT ;

	//}
	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//{
	//	tankbase.rotation -= 10.0f * DT;

	//}
	//if (input->isKeyDown(aie::INPUT_KEY_UP))
	//{
	//	tankTurret.rotation += 10.0f * DT;

	//}
	//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	//{
	//	tankTurret.rotation -= 10.0f * DT ;

	//}

	Object::Update(DT);
	paddle.Update(DT);
}

void Player::draw()
{
	Object::Draw();
	paddle.Draw();
}


