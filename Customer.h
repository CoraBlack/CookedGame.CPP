//�˿�costomer������
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"Restaurant.h"
#include"Thread.h"
class Customer
{
public:
	Customer();										//���캯��
	~Customer();
	//void CreateCustomer();						//���ɹ˿�
	float GetPayAmount();							//��ȡ�˿Ͷ�������
	void SetPayAmount(float set);					//���ù˿Ͷ�������
	;
	std::vector<cuisine>needs;						//�˿͵Ķ�������
//���ھͲ�(����)
	/*
	void Enter();									//����
	void Leave();									//�뿪
	*/
	;
//��������
	void RequestedMessage();						//����ҷ���������Ϣ
	void Waitting();								//�˿ͽ���ȴ�״̬
	;
//��������
	//���ù˿�����״̬
	inline void SetNeedsState(bool set_state) { needsstate = set_state; return; };
	//��ȡ�˿�����״̬
	inline bool GetNeedsState() { return needsstate; };
private:
	Thread* custrd;									//�߳�
	int wait_time_min = 30'000;						//Ĭ������ʮ��(ǧ��֮һ��Ϊ��λ)
	int wait_time_max = 90'000;						//Ĭ����һ�ְ���(ǧ��֮һ��Ϊ��λ)
	float pay_amount = 0;							//�˿��µ���Ԥ�Ʊ���
	bool needsstate = 0;							//�˿������״̬(0Ϊδ���㣬1Ϊ����)
};
#endif 
