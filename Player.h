//���Player������
#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include"IngredientMarketUI.h"
class Player
{
public:
	std::vector<ingredient*>hand;			//�ֳ���Ʒ(ʳ��)���ֻ��ͬʱ����������
	void SetPlayerLocation(int loc);
	void SetPlayerName(std::string str);	//�����������
	void SetPlayerMoney(float fl);			//�������Ǯ��
	std::string GetPlayerName();			//��ȡ�������
	float GetPlayerMoney();					//��ȡ���Ǯ��
	
private:

	std::string name = "";			//�������
	float money = 1000;				//������
	int location = 0;				//������ڲ���λ��
};
extern Player* player;
#endif // !PLAYER_H
