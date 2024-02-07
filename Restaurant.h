
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include "IngredientMarketUI.h"
class Restaurant
{
public:
//����
	void SetLevel(int num);				//���ò͹ݵȼ�
	void SetCostomerMax(int num);		//��������ɿ���
	void SetWareHouseMax(int num);		//�����������
	bool GetOpenState();				//��ȡ����Ӫҵ״̬
	void SetOpenState(bool set_state);	//���õ���Ӫҵ״̬
//����
	std::vector<ingredient*>ice_box;						  //���䣨ʳ�Ĵ����
	void SwapIngredient(ingredient*& ing1, ingredient*& ing2);//����Ϊ���������Ľ�������(��������ָ�������)
	void IceBoxSort();										  //���䰴˳�����л���(��ĸ��Сд)
private:
	int level = 0;						//�͹ݵȼ�
	int cosmax = 50;					//����ɿ���
	int warehouse = 0;					//��������
	bool openstate = 0;					//Ӫҵ״̬
};
extern Restaurant* restaurant;
#endif
