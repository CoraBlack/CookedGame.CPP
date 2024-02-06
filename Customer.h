//顾客costomer类的设计
#ifndef COSTOMER_H
#define COSTOMER_H
class Customer
{
public:
	int num;
	Customer();
	~Customer();
	void SwapObject(Customer* cos1, Customer* cos2);//交换两个Costomer类对象的函数
	void Count();									//计时器
	void Enter();									//进店
	void Leave();									//离开
private:
	float wait_time_min = 0;
	float wait_time_max = 0;
};
#endif
