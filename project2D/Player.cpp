#include "Player.h"
#include <iostream>
#include "BSM.h"


Player::Player(float PosX, float PosY)
{
	position = {PosX,PosY};

	width = 15;

	velcocity = { 10,10 };

	BM = new BSM();


}


Player::~Player()
{
	delete BM;
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



