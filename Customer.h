//�˿�costomer������
#ifndef COSTOMER_H
#define COSTOMER_H
class Customer
{
public:
	int num;
	Customer();
	~Customer();
	void SwapObject(Customer* cos1, Customer* cos2);//��������Costomer�����ĺ���
	void Count();									//��ʱ��
	void Enter();									//����
	void Leave();									//�뿪
private:
	float wait_time_min = 0;
	float wait_time_max = 0;
};
#endif
