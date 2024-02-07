
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include "IngredientMarketUI.h"
class Restaurant
{
public:
//餐厅
	void SetLevel(int num);				//设置餐馆等级
	void SetCostomerMax(int num);		//设置最大纳客量
	void SetWareHouseMax(int num);		//设置最大存货量
	bool GetOpenState();				//获取店铺营业状态
	void SetOpenState(bool set_state);	//设置店铺营业状态
//冰箱
	std::vector<ingredient*>ice_box;						  //冰箱（食材存货）
	void SwapIngredient(ingredient*& ing1, ingredient*& ing2);//用于为排序而服务的交换函数(交换的是指针的引用)
	void IceBoxSort();										  //冰箱按顺序排列货物(字母大小写)
private:
	int level = 0;						//餐馆等级
	int cosmax = 50;					//最大纳客量
	int warehouse = 0;					//最大货仓量
	bool openstate = 0;					//营业状态
};
extern Restaurant* restaurant;
#endif
