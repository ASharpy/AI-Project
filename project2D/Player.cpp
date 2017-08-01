#include "Player.h"
#include <iostream>


Player::Player(float PosX, float PosY)
{
	posX = PosX;

	posY = PosY;

	width = 15;

	Yvelocity = 0;

	Xvelocity = 0;

	

}


Player::~Player()
{
}
//
//void Player::setup(aie::Renderer2D * m_2dRenderer, aie::Texture * m_texture, aie::Texture * m_paddleTexture)
//{
//
//}
////getting a key press and changing the tank accordingly
//void Player::update(float DT , aie::Input * input)
//{
//
//}
//
//void Player::draw()
//{
//	



