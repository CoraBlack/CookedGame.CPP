//���Player������
#include<string>
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
	void SetPlayerName(std::string str);//�����������
	void SetPlayerMoney(float fl);//�������Ǯ��
	std::string GetPlayerName();//��ȡ�������
	float GetPlayerMoney();//��ȡ���Ǯ��
private:
	std::string name;
	float money = 0;
};
#endif // !PLAYER_H
