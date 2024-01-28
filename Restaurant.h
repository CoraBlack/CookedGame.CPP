#ifndef RESTAURANT_H
#define RESTAURANT_H
class Restaurant
{
public:
	void SetLevel();		//设置餐馆等级
	void SetCostomerMax(); //设置最大纳客量
	void SetWareHouseMax();//设置最大存货量
private:
	int level = 0;//餐馆等级
	int cosmax = 0;//最大纳客量
	int warehouse = 0;//最大货仓量
};
#endif
