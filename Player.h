//玩家Player类的设计
#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include"IngredientMarketUI.h"
class Player
{
public:
	std::vector<ingredient*>hand;			//手持物品(食材)最多只能同时拿两个东西
	void SetPlayerName(std::string str);	//设置玩家名称
	void SetPlayerMoney(float fl);			//设置玩家钱财
	unsigned int GetPlayerPlot();			//获取玩家通关剧情数
	void SetPlayerPlot(unsigned int set);	//设置玩家通关剧情数
	std::string GetPlayerName();			//获取玩家名称
	float GetPlayerMoney();					//获取玩家钱财
	
private:

	std::string name = "";			//玩家名称
	float money = 1000;				//玩家余额
	unsigned int plot = 0;			//玩家已通关剧情数
};
extern Player* player;
#endif // !PLAYER_H
