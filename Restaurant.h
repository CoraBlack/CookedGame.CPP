#ifndef RESTAURANT_H
#define RESTAURANT_H
class Restaurant
{
public:
	void SetLevel();		//���ò͹ݵȼ�
	void SetCostomerMax(); //��������ɿ���
	void SetWareHouseMax();//�����������
private:
	int level = 0;//�͹ݵȼ�
	int cosmax = 0;//����ɿ���
	int warehouse = 0;//��������
};
#endif
