#include"statement.h"
#include "Customer.h"
#include"Thread.h"
#include <functional>  
//构造函数
Customer::Customer(){
//将自身存入顾客集
	customers.push_back(this);
	//函数对象
	auto funcobj = std::bind(&Customer::RequestedMessage, &*this);
	custrd = nullptr;
	custrd = new Thread(funcobj);
	return;
}
//析构函数
Customer::~Customer() {
//销毁后台操作线程
	delete custrd;
	custrd = nullptr;
	return;
}
;
float Customer::GetPayAmount() { return pay_amount; }
;
void Customer::SetPayAmount(float set) { pay_amount = set; return; }
;
void Customer::RequestedMessage(){
//为顾客添加需求
	for (int i = 0; i < Random(1, 3);) {
	//随机需求
		int kind = Random(0, restaurant->all_cuisine.size() - 1);
		needs.push_back(*(restaurant->all_cuisine[kind]));
		pay_amount += restaurant->all_cuisine[kind]->price;
		i++;
	}
	//加上小费
	pay_amount += Random(0, pay_amount * 0.8);
	std::cout << yellow << "Message:" << green << "新的顾客!\n";
	//进入等待状态
	return this->Waitting();
}
;
void Customer::Waitting(){
//for循环中每0.1秒检测一次
	int time = Random(wait_time_min, wait_time_max) / 100;
	for (int i = 0; i < time;) {
		Sleep(100);
//尝试上锁已判断能否暂停函数
	//若暂停则上锁
		if (pausestate) {
		//上锁堵塞线程
			mtx_pause->lock();
			mtx_pause->unlock();
		}
	//顾客订单完成后
		if (needsstate) {
		//增加营业额
			restaurant->SetTurnover(restaurant->GetTurnover() + pay_amount);
		//销毁对象
			return DeleteCustomer(this);
		}
	//顾客订单在计时内未完成
		i++;
	}
//循环结束未跳出，意味未按时完成订单
	//发送订单失败信息
	std::cout << yellow << "\nMessage:您的手脚太慢了，有一位顾客已经离开\n" << white;
	//扣除营业额
	restaurant->SetTurnover(restaurant->GetTurnover() - pay_amount);
	//销毁对象
	return DeleteCustomer(this);
}

