#ifndef RESTAURANTUI_H
#define RESTAURANTUI_H
#include "MainGui.h"
#include"vector"
#include <string>
class RestaurantUI :public MainGui {
public:
	void MainResMenu();
	void ResOpenMenu();	//营业时操作界面
private:
	std::vector<std::string>messages;	//信息暂存管理区
};
extern RestaurantUI* res_weight;
#endif
