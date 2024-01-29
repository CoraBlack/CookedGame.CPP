#include "Player.h"

void Player::SetPlayerLocation(int loc) { location = loc; return; }

void Player::SetPlayerName(std::string str){ name = str; return; }

void Player::SetPlayerMoney(float setmoney) { money = setmoney; return; }

std::string Player::GetPlayerName(){ return name; }

float Player::GetPlayerMoney(){ return money; }
