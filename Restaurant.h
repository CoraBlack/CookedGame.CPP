#ifndef RESTAURANT_H
#define RESTAURANT_H
class Restaurant
{
public:
<<<<<<< HEAD
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
=======
	void SetLevel(int num);		//���ò͹ݵȼ�
	void SetCostomerMax(int num); //��������ɿ���
	void SetWareHouseMax(int num);//�����������
	void SetOpenState(bool state);//���õ���Ӫҵ״̬
	bool GetOpenState();//��ȡ����Ӫҵ״̬
private:
	int level = 0;//�͹ݵȼ�
	int cosmax = 0;//����ɿ���
	int warehouse = 0;//��������
	bool open = 0;//Ӫҵ״̬
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
};
extern Restaurant* restaurant;
#endif
