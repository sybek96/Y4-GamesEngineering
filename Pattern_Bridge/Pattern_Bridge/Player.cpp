#include "Player.h"



Player::Player(DrawAPI* api)
{
	this->api = api;
}


Player::~Player()
{
}

void Player::Draw()
{
	api->Draw();
}
