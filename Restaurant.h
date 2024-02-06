#ifndef RESTAURANT_H
#define RESTAURANT_H
class Restaurant
{
public:
<<<<<<< HEAD
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
=======
	void SetLevel(int num);		//设置餐馆等级
	void SetCostomerMax(int num); //设置最大纳客量
	void SetWareHouseMax(int num);//设置最大存货量
	void SetOpenState(bool state);//设置店铺营业状态
	bool GetOpenState();//获取店铺营业状态
private:
	int level = 0;//餐馆等级
	int cosmax = 0;//最大纳客量
	int warehouse = 0;//最大货仓量
	bool open = 0;//营业状态
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
};
extern Restaurant* restaurant;
#endif
