#include "Player.h"

void Player::SetPlayerName(std::string str)
{
	name = str;
	return;
}

void Player::SetPlayerMoney(float fl)
{
}

std::string Player::GetPlayerName(){ return name; }

float Player::GetPlayerMoney(){ return money; }
