#include "Customer.h"
#include"statement.h"
//构造函数
Customer::Customer(){
	//生成顾客时存入顾客
	customers.push_back(this);
}
Customer::~Customer(){

	//查找自身在向量中的位置
	for (int i = 0; i < customers.size();) {
		if (this == customers[i]) {
			//交换移出
			SwapObject(customers[i], customers.back());
			customers.pop_back();
			return;
		}
		i++;
	}
	std::cerr << red << "（顾客）找不到在向量中的位置" << white;
	return;
}
void Customer::SwapObject(Customer* cos1, Customer* cos2){
	Customer cos_temp = *cos1;	//临时存值
	//交换值(所指内存地址不变)
	*cos2 = *cos1;				
	*cos1 = cos_temp;
	return;
}

void Customer::Count(){
}

void Customer::Enter(){
}

void Customer::Leave(){
}

