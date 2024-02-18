#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include "IngredientMarketUI.h"
//����
struct cuisine {
	std::string name;
	int price;							//�۸�
	int time;							//�ϳ�ʱ��
	std::vector<ingredient*>formulation;//�䷽
};
class Restaurant
{
public:
//����
	std::vector<std::string>requiedment;//�˿͵��������ּ���
//����
	//Level 0
	cuisine chicken_burger = { "���ź���",8 ,10'000 ,{&market_weight->low_burger_bun,&market_weight->low_Chicken_chops}};
	cuisine beef_burger = { "ţ�ź���" , 11 , 10'000 , {&market_weight->low_beef_chops,&market_weight->low_burger_bun} };
	cuisine pork_burger = { "���ź���" , 10 , 10'000 , {&market_weight->low_burger_bun,&market_weight->low_pork_chops} };

	//Level 1


	//all//ȫ������
	std::vector<cuisine*>all_cuisine = {
		&chicken_burger,
		&beef_burger,
		&pork_burger
	};
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
