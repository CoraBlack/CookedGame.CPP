#ifndef INGREDIENTMARKETUI_H
#define INGREDIENTMARKETUI_H
#include"MainGui.h"
#include<vector>
#include<string>
//ʳ�Ľṹ��
struct ingredient {
	std::string name;
	int id;					//ʳ��ID[ʹ����λ�����λ�����ϣ���һλΪʳ�����ͣ��ӵڶ�λ���Ϊ��ǰ����������]
	unsigned grade;			//ʳ�ĵȼ�(1Ϊ�ͼ�,2Ϊһ��,3Ϊ�߼�)
	float price;			//�۸�
	int possession;			//ӵ����
};
class IngredientMarketUI:public MainGui{
public:

//ʳ��
	//�߲���



	//����
	ingredient low_beef_chops = { "���Ʒţ��(�ͼ�)",21,1,6,0 };

	ingredient low_pork_chops = { "���Ʒ����(�ͼ�)",22,1,5,0 };

	ingredient low_Chicken_chops = { "���Ʒ����(�ͼ�)",23,1,4,0 };

	//������
	ingredient low_burger_bun = { "�������(�ͼ�)",31,1,0.5,0 };

	

//�洢����
	std::vector<ingredient*>vegetable = {

	};//�߲���ʳ��

	std::vector<ingredient*>meat = {
		&low_beef_chops,
		&low_pork_chops,
		&low_Chicken_chops
	};//����ʳ��

	std::vector<ingredient*>cereals = {
		&low_burger_bun
	};//������ʳ��


	std::vector <std::vector<ingredient*>> all_ingredient;//ȫ��ʳ��

//��Ա����
	IngredientMarketUI();											//��ʼ�����캯��
	void IngredientMarket();										//ʳ���г�
	void ShoppingCartOperator();									//���ﳵ�Ĳ�������
	void ChooseSomeIngredient(std::vector<ingredient*>&vec);		//ʳ������б�
	
private:
//�洢����
	int page = 0;											//����б�ҳ��(���㿪ʼΪ��һҳ)
	float total_price = 0;									//ѡ���ܼ�
	std::vector<ingredient*>shopping_cart;					//ʳ�Ĺ��ﳵ
};
extern IngredientMarketUI* market_weight;
#endif
