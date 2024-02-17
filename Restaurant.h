#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include "IngredientMarketUI.h"
//����
struct cuisine {
	std::string name;
	int price;				//�۸�
};
class Restaurant
{
public:
//����
	std::vector<std::string>requiedment;//�˿͵��������ּ���
//����
	//Level 0
	cuisine fry_chicken_chops = { "���ź���",8 };
	//Level 1

	//Level 2
	std::vector<cuisine>all_cuisine;	//ȫ������
	void Level_1();						//�����������ȼ�1
//̯λ
	Restaurant();
	void SetLevel(int num);				//���ò͹ݵȼ�
	unsigned int GetLevel();			//��ȡ�����ȼ�
	void SetCostomerMax(int num);		//��������ɿ���
	void SetIceBoxMax(unsigned int num);//���ñ����������
	unsigned int GetIceBoxMax();		//��ȡ�����������
	bool GetOpenState();				//��ȡ����Ӫҵ״̬
	void SetOpenState(bool set_state);	//���õ���Ӫҵ״̬
	float GetTurnover();				//��ȡ����Ӫҵ��
	void SetTurnover(float set);		//���õ���Ӫҵ��
	std::vector<ingredient*>bin;		//С�Ƴ��ĳ�̯������
//����
	std::vector<ingredient*>ice_box;						  //���䣨ʳ�Ĵ����
	void SwapIngredient(ingredient*& ing1, ingredient*& ing2);//����Ϊ���������Ľ�������(��������ָ�������)
	void IceBoxSort();										  //���䰴˳�����л���(��ĸ��Сд)
private:
	float turnover = 0;					//������Ӫҵ��R
	unsigned int level = 0;				//�͹ݵȼ�(Ӫҵ��ÿ��ʮ������)
	int cosmax = 50;					//����ɿ���
	int icebox_max = 50;				//������������
	bool openstate = 0;					//Ӫҵ״̬(1Ϊ���ţ�
};
extern Restaurant* restaurant;
#endif
