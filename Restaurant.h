#ifndef RESTAURANT_H
#define RESTAURANT_H
class Restaurant
{
public:
	void SetLevel(int num);			//���ò͹ݵȼ�
	void SetCostomerMax(int num);	//��������ɿ���
	void SetWareHouseMax(int num);	//�����������
	void SetOpenState(int state);	//���õ���Ӫҵ״̬
	bool GetOpenState();			//��ȡ����Ӫҵ״̬
private:
	int level = 0;		//�͹ݵȼ�
	int cosmax = 0;		//����ɿ���
	int warehouse = 0;	//��������
	bool openstate = 0;	//Ӫҵ״̬
};
extern Restaurant* restaurant;
#endif
