#ifndef INGREDIENTMARKETUI_H
#define INGREDIENTMARKETUI_H
#include"MainGui.h"
#include<vector>
#include<string>
//食材结构体
struct ingredient {
	std::string name;
	int id;					//食材ID[使用两位或更多位数以上，第一位为食材类型，从第二位起才为当前类型中序数]
	unsigned grade;			//食材等级(1为低级,2为一般,3为高级)
	float price;			//价格
	int possession;			//拥有量
};
class IngredientMarketUI:public MainGui{
public:

//食材
	//蔬菜类



	//肉类
	ingredient low_beef_chops = { "半成品牛排(低级)",21,1,6,0 };

	ingredient low_pork_chops = { "半成品猪排(低级)",22,1,5,0 };

	ingredient low_Chicken_chops = { "半成品鸡扒(低级)",23,1,4,0 };

	//谷物类
	ingredient low_burger_bun = { "汉堡面包(低级)",31,1,0.5,0 };

	

//存储管理集
	std::vector<ingredient*>vegetable = {

	};//蔬菜类食材

	std::vector<ingredient*>meat = {
		&low_beef_chops,
		&low_pork_chops,
		&low_Chicken_chops
	};//肉类食材

	std::vector<ingredient*>cereals = {
		&low_burger_bun
	};//谷物类食材


	std::vector <std::vector<ingredient*>> all_ingredient;//全部食材

//成员函数
	IngredientMarketUI();											//初始化构造函数
	void IngredientMarket();										//食材市场
	void ShoppingCartOperator();									//购物车的操作界面
	void ChooseSomeIngredient(std::vector<ingredient*>&vec);		//食材浏览列表
	
private:
//存储数据
	int page = 0;											//浏览列表页数(从零开始为第一页)
	float total_price = 0;									//选购总价
	std::vector<ingredient*>shopping_cart;					//食材购物车
};
extern IngredientMarketUI* market_weight;
#endif
