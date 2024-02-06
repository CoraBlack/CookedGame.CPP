#ifndef RESTAURANT_H
#define RESTAURANT_H
class Restaurant
{
public:
	void SetLevel(int num);			//设置餐馆等级
	void SetCostomerMax(int num);	//设置最大纳客量
	void SetWareHouseMax(int num);	//设置最大存货量
	void SetOpenState(int state);	//设置店铺营业状态
	bool GetOpenState();			//获取店铺营业状态
private:
	int level = 0;		//餐馆等级
	int cosmax = 0;		//最大纳客量
	int warehouse = 0;	//最大货仓量
	bool openstate = 0;	//营业状态
};
extern Restaurant* restaurant;
#endif
