#ifndef RESTAURANTUI_H
#define RESTAURANTUI_H
#include "MainGui.h"
#include"vector"
#include <string>
class RestaurantUI :public MainGui {
public:
	void MainResMenu();			//餐厅主页面（关门时）
	void ResOpenMenu();			//营业时操作界面
	//void KitchenUI();			//餐厅厨房操作界面
	void IceBoxUI(int page);	//冰箱的操作界面
	void CookedUI();			//烹饪的操作界面
private:
	std::vector<std::string>messages;	//信息暂存管理区
};
extern RestaurantUI* res_weight;
#endif
