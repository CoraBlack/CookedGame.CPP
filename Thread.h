//�߳���
#include<thread>
#ifndef THREAD_H
#define THREAD_H
class Thread{
public:
	Thread();
	void ThreadStop();	//��ֹ����
	void ThreadPause();	//��ͣ����
	void ThreadRun();	//��������
private:
	std::thread trd;	//�߳�
	bool state = 0;		//�߳�״̬��0Ϊֹͣ��1Ϊ����
};
#endif
