#include "Customer.h"
#include"statement.h"
//���캯��
Customer::Customer(){
	//���ɹ˿�ʱ����˿�
	customers.push_back(this);
}
Customer::~Customer(){

	//���������������е�λ��
	for (int i = 0; i < customers.size();) {
		if (this == customers[i]) {
			//�����Ƴ�
			SwapObject(customers[i], customers.back());
			customers.pop_back();
			return;
		}
		i++;
	}
	std::cerr << red << "���˿ͣ��Ҳ����������е�λ��" << white;
	return;
}
void Customer::SwapObject(Customer* cos1, Customer* cos2){
	Customer cos_temp = *cos1;	//��ʱ��ֵ
	//����ֵ(��ָ�ڴ��ַ����)
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

