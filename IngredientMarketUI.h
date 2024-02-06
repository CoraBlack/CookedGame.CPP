#ifndef INGREDIENTMARKETUI_H
#define INGREDIENTMARKETUI_H
#include"MainGui.h"
#include<vector>
#include<string>
class IngredientMarketUI:public MainGui{
public:
//食材结构体
	struct ingredient {
		std::string name;
		unsigned grade;			//食材等级(1为低级,2为一般,3为高级)
		float price;			//价格
		int possession;			//拥有量
	};
	IngredientMarketUI();					//初始化构造函数
	void IngredientMarket();				//食材市场
	void ShoppingCartOperator();			//购物车的操作界面
	void ChooseSomeIngredient(std::vector<ingredient>&vec);			//食材浏览列表
	

private:
//食材
	ingredient low_beef = { "低级牛肉",1,40,0 };
	ingredient low_pork = { "低级猪肉",1,30,0 };
	ingredient low_chicken = { "低级鸡肉",1,25,0 };
	ingredient low_Chicken_chops = { "低级鸡扒",1,15,0 };

	;
	std::vector<ingredient>vegetable;						//蔬菜类食材
	std::vector<ingredient>meat;							//肉类食材
	std::vector <std::vector<ingredient>>all_ingredient;	//全部食材
	;
//存储数据
	int page = 0;									//浏览列表页数(从零开始为第一页)
	float total_price = 0;									//选购总价
	std::vector<ingredient>shopping_cart;					//食材购物车
};
extern IngredientMarketUI* market_weight;
#endif
