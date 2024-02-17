//���Player������
#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include"IngredientMarketUI.h"
class Player
{
public:
	std::vector<ingredient*>hand;			//�ֳ���Ʒ(ʳ��)���ֻ��ͬʱ����������
	void SetPlayerName(std::string str);	//�����������
	void SetPlayerMoney(float fl);			//�������Ǯ��
	unsigned int GetPlayerPlot();			//��ȡ���ͨ�ؾ�����
	void SetPlayerPlot(unsigned int set);	//�������ͨ�ؾ�����
	std::string GetPlayerName();			//��ȡ�������
	float GetPlayerMoney();					//��ȡ���Ǯ��
	
private:

	std::string name = "";			//�������
	float money = 1000;				//������
	unsigned int plot = 0;			//�����ͨ�ؾ�����
};
extern Player* player;
#endif // !PLAYER_H
