//顾客costomer类的设计
#ifndef COSTOMER_H
#define COSTOMER_H
#include"Restaurant.h"
#include"Thread.h"
class Customer
{
public:
	Customer();										//构造函数
	~Customer();
	//void CreateCustomer();						//生成顾客
	float GetPayAmount();							//获取顾客订单报酬
	void SetPayAmount(float set);					//设置顾客订单报酬
	;
//店内就餐(搁置)
	/*
	void Enter();									//进店
	void Leave();									//离开
	*/
	;
//线上外卖
	void RequestedMessage();						//向玩家发送需求信息
	void Waitting();								//顾客进入等待状态
	;
//内联函数
	//设置顾客需求状态
	inline void SetNeedsState(bool set_state) { needsstate = set_state; return; };
	//获取顾客需求状态
	inline bool GetNeedsState() { return needsstate; };
private:
	Thread* costrd;									//线程
	int wait_time_min = 180'000;					//默认是三分钟(千分之一秒为单位)
	int wait_time_max = 300'000;					//默认是五分钟(千分之一秒为单位)
	std::vector<cuisine>needs;						//顾客的订单需求
	float pay_amount = 0;							//顾客下单的预计报酬
	bool needsstate = 0;							//顾客需求的状态(0为未满足，1为满足)
};
#endif
