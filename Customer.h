//�˿�costomer������
#ifndef COSTOMER_H
#define COSTOMER_H
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
	Thread* costrd;									//�߳�
	int wait_time_min = 180'000;					//Ĭ����������(ǧ��֮һ��Ϊ��λ)
	int wait_time_max = 300'000;					//Ĭ���������(ǧ��֮һ��Ϊ��λ)
	std::vector<cuisine>needs;						//�˿͵Ķ�������
	float pay_amount = 0;							//�˿��µ���Ԥ�Ʊ���
	bool needsstate = 0;							//�˿������״̬(0Ϊδ���㣬1Ϊ����)
};
#endif
