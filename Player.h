//���Player������
#include<string>
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
	void SetPlayerLocation(int loc);
	void SetPlayerName(std::string str);//�����������
	void SetPlayerMoney(float fl);//�������Ǯ��
	std::string GetPlayerName();//��ȡ�������
	float GetPlayerMoney();//��ȡ���Ǯ��
	
private:
	std::string name = "";
<<<<<<< HEAD
	float money = 1000;
=======
	float money = 0;
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
	int location = 0;//������ڲ���λ��
};
extern Player* player;
#endif // !PLAYER_H
