//�߳���
#ifndef THREAD_H
#define THREAD_H
#include<thread>
#include<mutex>
#include <functional> 
class Thread{
public:
	Thread(std::function <void()> func);			//���캯���������̨�߳�
	~Thread();										//������������ֹ����
private:
	std::thread* trdworker;							//�߳�
	//bool state = 0;								//�߳�״̬��0Ϊֹͣ��1Ϊ����
};
#endif
