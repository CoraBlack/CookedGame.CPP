#ifndef INGREDIENTMARKETUI_H
#define INGREDIENTMARKETUI_H
#include"MainGui.h"
#include<vector>
#include<string>
class IngredientMarketUI:public MainGui{
public:
//ʳ�Ľṹ��
	struct ingredient {
		std::string name;
		unsigned grade;			//ʳ�ĵȼ�(1Ϊ�ͼ�,2Ϊһ��,3Ϊ�߼�)
		float price;			//�۸�
		int possession;			//ӵ����
	};
	IngredientMarketUI();					//��ʼ�����캯��
	void IngredientMarket();				//ʳ���г�
	void ShoppingCartOperator();			//���ﳵ�Ĳ�������
	void ChooseSomeIngredient(std::vector<ingredient>&vec);			//ʳ������б�
	

private:
//ʳ��
	ingredient low_beef = { "�ͼ�ţ��",1,40,0 };
	ingredient low_pork = { "�ͼ�����",1,30,0 };
	ingredient low_chicken = { "�ͼ�����",1,25,0 };
	ingredient low_Chicken_chops = { "�ͼ�����",1,15,0 };

	;
	std::vector<ingredient>vegetable;						//�߲���ʳ��
	std::vector<ingredient>meat;							//����ʳ��
	std::vector <std::vector<ingredient>>all_ingredient;	//ȫ��ʳ��
	;
//�洢����
	int page = 0;									//����б�ҳ��(���㿪ʼΪ��һҳ)
	float total_price = 0;									//ѡ���ܼ�
	std::vector<ingredient>shopping_cart;					//ʳ�Ĺ��ﳵ
};
extern IngredientMarketUI* market_weight;
#endif
