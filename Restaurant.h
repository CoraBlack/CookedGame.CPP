#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include "IngredientMarketUI.h"
//菜肴
struct cuisine {
	std::string name;
	int price;							//价格
	int time;							//合成时间
	std::vector<ingredient*>formulation;//配方
};
class Restaurant
{
public:
//请求
	std::vector<std::string>requiedment;//顾客的请求文字集合
//菜肴
	//Level 0
	cuisine chicken_burger = { "鸡排汉堡",8 ,10'000 ,{&market_weight->low_burger_bun,&market_weight->low_Chicken_chops}};
	cuisine beef_burger = { "牛排汉堡" , 11 , 10'000 , {&market_weight->low_beef_chops,&market_weight->low_burger_bun} };
	cuisine pork_burger = { "猪排汉堡" , 10 , 10'000 , {&market_weight->low_burger_bun,&market_weight->low_pork_chops} };

	//Level 1


	//all//全部菜肴
	std::vector<cuisine*>all_cuisine = {
		&chicken_burger,
		&beef_burger,
		&pork_burger
	};
	void Level_1();						//餐厅升级至等级1
//摊位
	Restaurant();
	void SetLevel(int num);				//设置餐馆等级
	unsigned int GetLevel();			//获取餐厅等级
	void SetCostomerMax(int num);		//设置最大纳客量
	void SetIceBoxMax(unsigned int num);//设置冰箱最大存货量
	unsigned int GetIceBoxMax();		//获取冰箱最大存货量
	bool GetOpenState();				//获取店铺营业状态
	void SetOpenState(bool set_state);	//设置店铺营业状态
	float GetTurnover();				//获取店铺营业额
	void SetTurnover(float set);		//设置店铺营业额
	std::vector<ingredient*>bin;		//小推车的出摊储物箱
//冰箱
	std::vector<ingredient*>ice_box;						  //冰箱（食材存货）
	void SwapIngredient(ingredient*& ing1, ingredient*& ing2);//用于为排序而服务的交换函数(交换的是指针的引用)
	void IceBoxSort();										  //冰箱按顺序排列货物(字母大小写)
private:
	float turnover = 0;					//餐厅的营业额R
	unsigned int level = 0;				//餐馆等级(营业额每翻十倍升级)
	int cosmax = 50;					//最大纳客量
	int icebox_max = 50;				//冰箱最大货仓量
	bool openstate = 0;					//营业状态(1为开门）
};
extern Restaurant* restaurant;
#endif
