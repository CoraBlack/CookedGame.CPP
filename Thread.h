//�߳���
#ifndef THREAD_H
#define THREAD_H
#include<thread>
#include<mutex>
#include"Customer.h"
#include <functional> 
class Thread{
public:
	std::mutex mtx;									//�߳�����������ͣ�̺߳���
	Thread(std::function <void()> func);			//���캯���������̨�߳�
	std::thread::id GetThreadID();					//��ȡ�̵߳�ID
	void PauseThread();								//��ͣ�߳�
	void StopThread();								//��ֹ����
private:
	std::thread* trdworker;						//�߳�
	bool state = 0;								//�߳�״̬��0Ϊֹͣ��1Ϊ����
};
#endif
