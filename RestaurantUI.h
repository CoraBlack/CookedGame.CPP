#ifndef RESTAURANTUI_H
#define RESTAURANTUI_H
#include "MainGui.h"
#include"vector"
#include <string>
class RestaurantUI :public MainGui {
public:
	void MainResMenu();
	void ResOpenMenu();	//Ӫҵʱ��������
private:
	std::vector<std::string>messages;	//��Ϣ�ݴ������
};
extern RestaurantUI* res_weight;
#endif
