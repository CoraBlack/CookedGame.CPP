#include "Player.h"

void Player::SetPlayerName(std::string str){ name = str; return; }

void Player::SetPlayerMoney(float setmoney) { money = setmoney; return; }

unsigned int Player::GetPlayerPlot() { return plot; }

void Player::SetPlayerPlot(unsigned int set) { plot = set; return; }

std::string Player::GetPlayerName(){ return name; }

float Player::GetPlayerMoney(){ return money; }
