#include"statement.h"
#include "Customer.h"
#include"Thread.h"
#include <functional>  
//���캯��
Customer::Customer(){
//���������˿ͼ�
	customers.push_back(this);
	//��������
	auto funcobj = std::bind(&Customer::RequestedMessage, &*this);
	custrd = nullptr;
	custrd = new Thread(funcobj);
	return;
}
//��������
Customer::~Customer() {
//���ٺ�̨�����߳�
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
//Ϊ�˿��������
	for (int i = 0; i < Random(1, 3);) {
	//�������
		int kind = Random(0, restaurant->all_cuisine.size() - 1);
		needs.push_back(*(restaurant->all_cuisine[kind]));
		pay_amount += restaurant->all_cuisine[kind]->price;
		i++;
	}
	//����С��
	pay_amount += Random(0, pay_amount * 0.8);
	std::cout << yellow << "Message:" << green << "�µĹ˿�!\n";
	//����ȴ�״̬
	return this->Waitting();
}
;
void Customer::Waitting(){
//forѭ����ÿ0.1����һ��
	int time = Random(wait_time_min, wait_time_max) / 100;
	for (int i = 0; i < time;) {
		Sleep(100);
//�����������ж��ܷ���ͣ����
	//����ͣ������
		if (pausestate) {
		//���������߳�
			mtx_pause->lock();
			mtx_pause->unlock();
		}
	//�˿Ͷ�����ɺ�
		if (needsstate) {
		//����Ӫҵ��
			restaurant->SetTurnover(restaurant->GetTurnover() + pay_amount);
		//���ٶ���
			return DeleteCustomer(this);
		}
	//�˿Ͷ����ڼ�ʱ��δ���
		i++;
	}
//ѭ������δ��������ζδ��ʱ��ɶ���
	//���Ͷ���ʧ����Ϣ
	std::cout << yellow << "\nMessage:�����ֽ�̫���ˣ���һλ�˿��Ѿ��뿪\n" << white;
	//�۳�Ӫҵ��
	restaurant->SetTurnover(restaurant->GetTurnover() - pay_amount);
	//���ٶ���
	return DeleteCustomer(this);
}

