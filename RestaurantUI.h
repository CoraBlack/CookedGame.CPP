#ifndef RESTAURANTUI_H
#define RESTAURANTUI_H
#include "MainGui.h"
#include"Restaurant.h"
#include"vector"
#include <string>
class RestaurantUI :public MainGui {
public:
	void MainResMenu();			//������ҳ�棨����ʱ��
	void ResOpenMenu();			//Ӫҵʱ��������
	//void KitchenUI();			//����������������
	void IceBoxUI(int page);	//����Ĳ�������
	void CookedUI(int page);	//��⿵Ĳ�������
	void ProcessRequit();		//����˿�����
private:
	std::vector<std::string>messages;	//��Ϣ�ݴ������
};
extern RestaurantUI* res_weight;
#endif
