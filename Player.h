//玩家Player类的设计
#include<string>
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
	void SetPlayerLocation(int loc);
	void SetPlayerName(std::string str);//设置玩家名称
	void SetPlayerMoney(float fl);//设置玩家钱财
	std::string GetPlayerName();//获取玩家名称
	float GetPlayerMoney();//获取玩家钱财
	
private:
	std::string name;
	float money = 0;
	int location;//玩家所在餐厅位置
};
#endif // !PLAYER_H
